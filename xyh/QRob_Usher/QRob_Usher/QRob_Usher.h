#pragma once

// QRob_Usher.h : QRob_Usher.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CQRob_UsherApp : �й�ʵ�ֵ���Ϣ������� QRob_Usher.cpp��

class CQRob_UsherApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

