
// jcshili.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CjcshiliApp:
// �йش����ʵ�֣������ jcshili.cpp
//

class CjcshiliApp : public CWinApp
{
public:
	CjcshiliApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CjcshiliApp theApp;