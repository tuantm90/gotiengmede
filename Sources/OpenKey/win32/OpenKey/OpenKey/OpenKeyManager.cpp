/*----------------------------------------------------------
Vie-Type - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vie-type
-----------------------------------------------------------*/
#include "vie-typeManager.h"
#include <shlobj.h>

static vector<LPCTSTR> _inputType = {
	_T("Telex"),
	_T("VNI"),
	_T("Simple Telex"),
};

static vector<LPCTSTR> _tableCode = {
	_T("Unicode"),
	_T("TCVN3 (ABC)"),
	_T("VNI Windows"),
	_T("Unicode Tổ hợp"),
	_T("Vietnamese Locale CP 1258")
};

/*-----------------------------------------------------------------------*/

extern void vie-typeInit();
extern void vie-typeFree();

unsigned short  vie-typeManager::_lastKeyCode = 0;

vector<LPCTSTR>& vie-typeManager::getInputType() {
	return _inputType;
}

vector<LPCTSTR>& vie-typeManager::getTableCode() {
	return _tableCode;
}

void vie-typeManager::initEngine() {
	vie-typeInit();
}

void vie-typeManager::freeEngine() {
	vie-typeFree();
}

bool vie-typeManager::checkUpdate(string& newVersion) {
	wstring dataW = vie-typeHelper::getContentOfUrl(L"https://raw.githubusercontent.com/tuyenvm/vie-type/master/version.json");
	string data = wideStringToUtf8(dataW);

	//simple parse
	constexpr char versionNameStr[] = "\"versionName\":";
	constexpr char versionCodeStr[] = "\"versionCode\":";
	constexpr char numbers[] = "0123456789";
	size_t posBegin = string::npos;
	size_t posEnd = string::npos;

	posBegin = data.find("latestWinVersion");
	posBegin = data.find(versionNameStr, posBegin);
	posBegin += (sizeof(versionNameStr) - 1);
	posBegin = data.find('\"', posBegin);
	posBegin = data.find_first_of(numbers, posBegin);

	posEnd = data.find('\"', posBegin);

	if (posBegin == string::npos || posEnd == string::npos) {
		return false;
	}

	newVersion = data.substr(posBegin, posEnd - posBegin);

	posBegin = posEnd;
	posBegin = data.find(versionCodeStr, posBegin);
	posBegin += (sizeof(versionCodeStr) - 1);

	posEnd = data.find("}", posBegin);

	if (posBegin == string::npos || posEnd == string::npos) {
		return false;
	}

	auto shiftVersion = [](DWORD version) {
		return (version << 16) | (version & 0x00FF00) | (version >> 16 & 0xFF);
		};

	string newVersionCodeStr = data.substr(posBegin, posEnd - posBegin);
	DWORD newVersionCode = (DWORD)atoi(newVersionCodeStr.data());
	newVersionCode = shiftVersion(newVersionCode);

	DWORD currentVersionCode = vie-typeHelper::getVersionNumber();
	currentVersionCode = shiftVersion(currentVersionCode);

	return newVersionCode > currentVersionCode;
}

void vie-typeManager::createDesktopShortcut() {
	CoInitialize(NULL);
	IShellLink* pShellLink = NULL;
	HRESULT hres;
	hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_ALL,
							IID_IShellLink, (void**)&pShellLink);
	if (SUCCEEDED(hres)) {
		wstring path = vie-typeHelper::getFullPath();
		pShellLink->SetPath(path.c_str());
		pShellLink->SetDescription(_T("vie-type - Bộ gõ Tiếng Việt"));
		pShellLink->SetIconLocation(path.c_str(), 0);

		IPersistFile* pPersistFile;
		hres = pShellLink->QueryInterface(IID_IPersistFile, (void**)&pPersistFile);

		if (SUCCEEDED(hres)) {
			wchar_t desktopPath[MAX_PATH + 1];
			wchar_t savePath[MAX_PATH + 10];
			SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath);
			wsprintf(savePath, _T("%s\\vie-type.lnk"), desktopPath);
			hres = pPersistFile->Save(savePath, TRUE);
			pPersistFile->Release();
			pShellLink->Release();
		}
	}
}
