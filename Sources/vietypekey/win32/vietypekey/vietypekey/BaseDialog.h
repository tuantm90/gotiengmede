/*----------------------------------------------------------
vietypekey - The Cross platform Open source Vietnamese Keyboard application.

Copyright (C) 2025 tuantm90
Github: hhttps://github.com/tuantm90/vietypekey
-----------------------------------------------------------*/
#pragma once
#include "stdafx.h"
#define SET_DIALOG_ICON(ICON_RES) HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_APP_ICON)); \
								if (hIcon) { \
									SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIcon); \
								}
class BaseDialog {
protected:
	UINT resId;
	HINSTANCE hInstance;
	HWND hDlg;
protected:
	void createToolTip(const HWND& control, LPCTSTR toolTipString);
	void createToolTip(const HWND& control, const UINT& stringResId);
	virtual INT_PTR eventProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
public:
	BaseDialog(const HINSTANCE& hInstance, const int& resourceId);
	void show();
	void bringOnTop();
	virtual void fillData() = 0;

	HWND getHwnd();
	void closeDialog();
	friend INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
