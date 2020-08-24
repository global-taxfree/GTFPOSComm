// GTFPOSCommCtrl.cpp : CGTFPOSCommCtrl ActiveX 컨트롤 클래스의 구현입니다.

#include "stdafx.h"
#include "GTFPOSComm.h"
#include "GTFPOSCommCtrl.h"
#include "GTFPOSCommPropPage.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CGTFPOSCommCtrl, COleControl)



// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CGTFPOSCommCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// 디스패치 맵입니다.

BEGIN_DISPATCH_MAP(CGTFPOSCommCtrl, COleControl)
	DISP_FUNCTION_ID(CGTFPOSCommCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CGTFPOSCommCtrl, "GTF_RequestApproval", dispidGTF_RequestApproval, GTF_RequestApproval, VT_I4, VTS_PI1 VTS_I4 VTS_PI1 VTS_I4 VTS_PI1 VTS_I4)
	DISP_FUNCTION_ID(CGTFPOSCommCtrl, "GTF_SetOffLineMode", dispidGTF_SetOffLineMode, GTF_SetOffLineMode, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()



// 이벤트 맵입니다.

BEGIN_EVENT_MAP(CGTFPOSCommCtrl, COleControl)
END_EVENT_MAP()



// 속성 페이지입니다.

// TODO: 필요에 따라 속성 페이지를 추가합니다. 카운트도 이에 따라 증가해야 합니다.
BEGIN_PROPPAGEIDS(CGTFPOSCommCtrl, 1)
	PROPPAGEID(CGTFPOSCommPropPage::guid)
END_PROPPAGEIDS(CGTFPOSCommCtrl)



// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CGTFPOSCommCtrl, "GTFPOSCOMM.GTFPOSCommCtrl.1",
	0x45d79fa2, 0x341, 0x4aa3, 0xb3, 0x1a, 0xe3, 0xcb, 0x37, 0x83, 0x3b, 0xdd)



// 형식 라이브러리 ID와 버전입니다.

IMPLEMENT_OLETYPELIB(CGTFPOSCommCtrl, _tlid, _wVerMajor, _wVerMinor)



// 인터페이스 ID입니다.

const IID IID_DGTFPOSComm = { 0xC9E948B8, 0xCF0D, 0x4E62, { 0xAB, 0xB, 0xB, 0x7D, 0xE7, 0xA7, 0xBE, 0x3D } };
const IID IID_DGTFPOSCommEvents = { 0x9F2AEF6, 0x14BC, 0x4CEE, { 0xA3, 0x1F, 0x57, 0x70, 0x89, 0x2A, 0x37, 0xD2 } };


// 컨트롤 형식 정보입니다.

static const DWORD _dwGTFPOSCommOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CGTFPOSCommCtrl, IDS_GTFPOSCOMM, _dwGTFPOSCommOleMisc)



// CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::UpdateRegistry -
// CGTFPOSCommCtrl에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 컨트롤이 아파트 모델 스레딩 규칙을 준수하는지
	// 확인합니다. 자세한 내용은 MFC Technical Note 64를
	// 참조하십시오. 컨트롤이 아파트 모델 규칙에
	// 맞지 않는 경우 다음에서 여섯 번째 매개 변수를 변경합니다.
	// afxRegApartmentThreading을 0으로 설정합니다.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_GTFPOSCOMM,
			IDB_GTFPOSCOMM,
			afxRegApartmentThreading,
			_dwGTFPOSCommOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// 라이선스 문자열입니다.

static const TCHAR _szLicFileName[] = _T("GTFPOSComm.lic");

static const WCHAR _szLicString[] = L"Copyright (c) 2016 ";



// CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::VerifyUserLicense -
// 사용자  라이선스가 있는지 검사합니다.

BOOL CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}



// CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::GetLicenseKey -
// 런타임  라이선스 키를 반환합니다.

BOOL CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR *pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


// CGTFPOSCommCtrl::CGTFPOSCommCtrl - 생성자입니다.

CGTFPOSCommCtrl::CGTFPOSCommCtrl()
{
	InitializeIIDs(&IID_DGTFPOSComm, &IID_DGTFPOSCommEvents);
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 초기화합니다.
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	hIns = LoadLibrary(_T("C:\\works\\GTF_COMM_DLL32\\GTF_COMM_DLL32\\Release\\GTF_COMM_DLL32.dll"));
	//hIns = LoadLibrary(_T("C:\\works\\GTF_COMM_DLL32\\GTF_COMM_DLL32\\Debug\\GTF_COMM_DLL32.dll"));

	if( hIns == NULL ) {
		printf("Load Library fail\n");
		
	}
	printf("Load End");

	fGTF_SetOffLineMode = (defGTF_SetOffLineMode)GetProcAddress( hIns, "GTF_SetOffLineMode" );
	fGTF_RequestApproval = (defGTF_RequestApproval)GetProcAddress( hIns, "GTF_RequestApproval" );

}



// CGTFPOSCommCtrl::~CGTFPOSCommCtrl - 소멸자입니다.

CGTFPOSCommCtrl::~CGTFPOSCommCtrl()
{
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 정리합니다.
}



// CGTFPOSCommCtrl::OnDraw - 그리기 함수입니다.

void CGTFPOSCommCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 다음 코드를 사용자가 직접 작성한 그리기 코드로 바꾸십시오.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CGTFPOSCommCtrl::DoPropExchange - 지속성 지원입니다.

void CGTFPOSCommCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 지속적인 사용자 지정 속성 모두에 대해 PX_ functions를 호출합니다.
}



// CGTFPOSCommCtrl::OnResetState - 컨트롤을 기본 상태로 다시 설정합니다.

void CGTFPOSCommCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange에 들어 있는 기본값을 다시 설정합니다.

	// TODO: 여기에서 다른 모든 컨트롤의 상태를 다시 설정합니다.
}



// CGTFPOSCommCtrl::AboutBox - "정보" 대화 상자를 사용자에게 보여 줍니다.

void CGTFPOSCommCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_GTFPOSCOMM);
	dlgAbout.DoModal();
}



// CGTFPOSCommCtrl 메시지 처리기입니다.


LONG CGTFPOSCommCtrl::GTF_RequestApproval(CHAR* P_Addr, LONG P_Port, CHAR* RequestMsg, LONG RequestLen, CHAR* RecvMsg, LONG ReadTimeOut)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 여기에 디스패치 처리기를 추가합니다.
	return fGTF_RequestApproval(P_Addr, P_Port, RequestMsg, RequestLen, RecvMsg, ReadTimeOut);

}


void CGTFPOSCommCtrl::GTF_SetOffLineMode(LONG Mode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: 여기에 디스패치 처리기를 추가합니다.
	fGTF_SetOffLineMode(Mode);
}
