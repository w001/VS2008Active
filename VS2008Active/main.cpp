#include <windows.h>
#include <stdio.h>

void OnBnClickedButtonAutoreg()
{
	// Ҫ���ҵ�VS2008�汾�б�
	const TCHAR* szCaption[] = {
		TEXT("Microsoft Visual Studio 2008 ��װ���� - ά��ҳ"),  // �������İ�
		TEXT("Microsoft Visual Studio 2008 ���b��ʽ - �S�o�"),  // �������İ�
		TEXT("Microsoft Visual Studio 2008 Setup - Maintenance Page"),   // Ӣ�İ�
		TEXT("Microsoft Visual Studio 2008 ���åȥ��å� - ���ƥʥ� �ک`��") // ���İ�
	};

	HWND hWnd;
	UINT i, uNum;

	// ��λ��Microsoft Visual Studio 2008 ��װ���� - ά��ҳ������
	uNum = sizeof(szCaption) / sizeof(const TCHAR*);
	for( i = 0; i < uNum; i++ )
	{
		hWnd = ::FindWindow( NULL, szCaption[i] );
		if( hWnd != NULL )
		{ // ���ڷ���
			break;
		}
	}

	if( i == uNum )
	{ // û���ҵ�VS2008ά��ҳ����
		::MessageBox(0, TEXT("û�з��֡�Microsoft Visual Studio 2008 ��װ���� - ά��ҳ�����ڣ�"), 0, 0);
		return;
	}

	// �����1���Ӵ���
	hWnd = :: GetTopWindow( hWnd );

	// �����4���Ӵ���
	for( i = 0; i < 3; i++ )
	{
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// �����2���Ӵ���
	hWnd = :: GetTopWindow( hWnd );

	// �����9���Ӵ���
	for( i = 0; i < 8; i++ )
	{
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// ����ע������д����
	for( i = 0; i < 5; i++ )
	{ // �����ı���
		::ShowWindow( hWnd, SW_SHOW );
		::EnableWindow( hWnd, TRUE );

		// ������һ���ı���
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// ����������ť
	for( i = 0; i < 2; i++ )
	{
		hWnd = :: GetNextWindow( hWnd, GW_HWNDNEXT );
	}

	// ����������ť
	::ShowWindow( hWnd, SW_SHOW );
	::EnableWindow( hWnd, TRUE );

	return;
}



void main()
{
	OnBnClickedButtonAutoreg();
}