/*----------------------------------------------------------
vietypekey - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vietypekey
-----------------------------------------------------------*/

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <vector>

#include <shellapi.h>
#include <Commctrl.h>
#include <psapi.h>

#include "resource.h"

#include "../../../engine/Engine.h"

#include "vietypekeyManager.h"
#include "vietypekeyHelper.h"
#include "SystemTrayHelper.h"

using namespace std;

extern wchar_t _logBuffer[1024];
#define LOG(...)  wsprintfW(_logBuffer, __VA_ARGS__); \
					OutputDebugString(_logBuffer);

#define APP_SET_DATA(KEY, VAL) KEY = VAL; vietypekeyHelper::setRegInt(_T(#KEY), KEY)
#define APP_GET_DATA(KEY, DEFAULT_VAL) KEY = vietypekeyHelper::getRegInt(_T(#KEY), DEFAULT_VAL)

#define APP_CLASS _T("vietypekeyVietnameseInputMethod")

extern void saveSmartSwitchKeyData();

extern int vLanguage;
extern int vInputType;
extern int vFreeMark;
extern int vCodeTable;
extern int vCheckSpelling;
extern int vUseModernOrthography;
extern int vQuickTelex;
extern int vSwitchKeyStatus;
extern int vRestoreIfWrongSpelling;
extern int vFixRecommendBrowser;
extern int vUseMacro;
extern int vUseMacroInEnglishMode;
extern int vAutoCapsMacro;
extern int vSendKeyStepByStep;
extern int vUseSmartSwitchKey;
extern int vUpperCaseFirstChar;
extern int vUseGrayIcon;
extern int vShowOnStartUp;
extern int vRunWithWindows;
extern int vSupportMetroApp;
extern int vCreateDesktopShortcut;
extern int vRunAsAdmin;
extern int vCheckNewVersion;
extern int vRememberCode;
extern int vOtherLanguage;
extern int vTempOffvietypekey;
extern int vFixChromiumBrowser;
