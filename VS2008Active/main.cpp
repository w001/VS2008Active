#include <windows.h>
#include <stdio.h>

void OnBnClickedButtonAutoreg()
{
	// 要查找的VS2008版本列表
	const TCHAR* szCaption[] = {
		TEXT("Microsoft Visual Studio 2008 安装程序 - 维护页"),  // 简体中文版
		TEXT("Microsoft Visual Studio 2008 安裝程式 - 維護頁"),  // 繁体中文版
		TEXT("Microsoft Visual Studio 2008 Setup - Maintenance Page"),   // 英文版
		TEXT("Microsoft Visual Studio 2008 セットアップ - メンテナンス ページ") // 日文版
	};

	HWND hWnd;
	UINT i, uNum;

	// 定位“Microsoft Visual Studio 2008 安装程序 - 维护页”窗口
	uNum = sizeof(szCaption) / sizeof(const TCHAR*);
	for( i = 0; i < uNum; i++ )
	{
		hWnd = ::FindWindow( NULL, szCaption[i] );
		if( hWnd != NULL )
		{ // 窗口发现
			break;
		}
	}

	if( i == uNum )
	{ // 没有找到VS2008维护页窗口
		::MessageBox(0, TEXT("没有发现“Microsoft Visual Studio 2008 安装程序 - 维护页”窗口！"), 0, 0);
		return;
	}

	// 进入第1层子窗口
	hWnd = :: GetTopWindow( hWnd );

	// 进入第4个子窗口
	for( i = 0; i < 3; i++ )
	{
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// 进入第2层子窗口
	hWnd = :: GetTopWindow( hWnd );

	// 进入第9个子窗口
	for( i = 0; i < 8; i++ )
	{
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// 进入注册码填写窗口
	for( i = 0; i < 5; i++ )
	{ // 激活文本框
		::ShowWindow( hWnd, SW_SHOW );
		::EnableWindow( hWnd, TRUE );

		// 进入下一个文本框
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// 进入升级按钮
	for( i = 0; i < 2; i++ )
	{
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// 激活升级按钮
	::ShowWindow( hWnd, SW_SHOW );
	::EnableWindow( hWnd, TRUE );

	return;
}



void main()
{
	OnBnClickedButtonAutoreg();
}