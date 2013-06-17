// QRob_Usher.cpp : CQRob_UsherApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "QRob_Usher.h"
#include "CDQrobotEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CQRob_UsherApp theApp;

const GUID CDECL _tlid = { 0x871CD819, 0x5001, 0x4684, { 0xA1, 0xAF, 0x69, 0x62, 0x84, 0x47, 0x86, 0xF5 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CQRob_UsherApp::InitInstance - DLL 初始化

BOOL CQRob_UsherApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CQRob_UsherApp::ExitInstance - DLL 终止

int CQRob_UsherApp::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
