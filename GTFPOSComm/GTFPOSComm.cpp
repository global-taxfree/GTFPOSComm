// GTFPOSComm.cpp : CGTFPOSCommApp �� DLL ����� �����Դϴ�.

#include "stdafx.h"
#include "GTFPOSComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CGTFPOSCommApp theApp;

const GUID CDECL _tlid = { 0x1F2D1D9B, 0xB695, 0x4B5F, { 0xA7, 0xFD, 0xC2, 0x80, 0x32, 0x85, 0x5E, 0x4D } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CGTFPOSCommApp::InitInstance - DLL �ʱ�ȭ�Դϴ�.

BOOL CGTFPOSCommApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();
	//MessageBox(NULL, (LPCWSTR)L"DLL Init",(LPCWSTR)L"ActivXReg",MB_OK);

	if (bInit)
	{
		// TODO: ���⿡ ���� �ۼ��� ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
		//MessageBox(NULL, (LPCWSTR)L"DLL Init Success",(LPCWSTR)L"ActivXReg",MB_OK);
	}

	return bInit;
}



// CGTFPOSCommApp::ExitInstance - DLL �����Դϴ�.

int CGTFPOSCommApp::ExitInstance()
{
	// TODO: ���⿡ ���� �ۼ��� ��� ���� �ڵ带 �߰��մϴ�.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - �ý��� ������Ʈ���� �׸��� �߰��մϴ�.

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	
	//MessageBox(NULL, (LPCWSTR)L"DLL REGISTER",(LPCWSTR)L"ActivXReg",MB_OK);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid)) {
		MessageBox(NULL, (LPCWSTR)L"SELFREG TYPELIB ERROR",(LPCWSTR)L"ActivXReg",MB_OK);
		return ResultFromScode(SELFREG_E_TYPELIB);
	}

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE)) {
		MessageBox(NULL, (LPCWSTR)L"UpdateRegistryAll ERROR",(LPCWSTR)L"ActivXReg",MB_OK);
		return ResultFromScode(SELFREG_E_CLASS);
	}
	return NOERROR;
}



// DllUnregisterServer - �ý��� ������Ʈ������ �׸��� �����մϴ�.

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	//MessageBox(NULL, (LPCWSTR)L"DLL UNREGISTER",(LPCWSTR)L"ActivXReg",MB_OK);
	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
