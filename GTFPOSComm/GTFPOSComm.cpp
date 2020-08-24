// GTFPOSComm.cpp : CGTFPOSCommApp 및 DLL 등록의 구현입니다.

#include "stdafx.h"
#include "GTFPOSComm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CGTFPOSCommApp theApp;

const GUID CDECL _tlid = { 0x1F2D1D9B, 0xB695, 0x4B5F, { 0xA7, 0xFD, 0xC2, 0x80, 0x32, 0x85, 0x5E, 0x4D } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CGTFPOSCommApp::InitInstance - DLL 초기화입니다.

BOOL CGTFPOSCommApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();
	//MessageBox(NULL, (LPCWSTR)L"DLL Init",(LPCWSTR)L"ActivXReg",MB_OK);

	if (bInit)
	{
		// TODO: 여기에 직접 작성한 모듈 초기화 코드를 추가합니다.
		//MessageBox(NULL, (LPCWSTR)L"DLL Init Success",(LPCWSTR)L"ActivXReg",MB_OK);
	}

	return bInit;
}



// CGTFPOSCommApp::ExitInstance - DLL 종료입니다.

int CGTFPOSCommApp::ExitInstance()
{
	// TODO: 여기에 직접 작성한 모듈 종료 코드를 추가합니다.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 시스템 레지스트리에 항목을 추가합니다.

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



// DllUnregisterServer - 시스템 레지스트리에서 항목을 제거합니다.

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
