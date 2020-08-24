// GTFPOSCommCtrl.cpp : CGTFPOSCommCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "GTFPOSComm.h"
#include "GTFPOSCommCtrl.h"
#include "GTFPOSCommPropPage.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CGTFPOSCommCtrl, COleControl)



// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CGTFPOSCommCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// ����ġ ���Դϴ�.

BEGIN_DISPATCH_MAP(CGTFPOSCommCtrl, COleControl)
	DISP_FUNCTION_ID(CGTFPOSCommCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CGTFPOSCommCtrl, "GTF_RequestApproval", dispidGTF_RequestApproval, GTF_RequestApproval, VT_I4, VTS_PI1 VTS_I4 VTS_PI1 VTS_I4 VTS_PI1 VTS_I4)
	DISP_FUNCTION_ID(CGTFPOSCommCtrl, "GTF_SetOffLineMode", dispidGTF_SetOffLineMode, GTF_SetOffLineMode, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()



// �̺�Ʈ ���Դϴ�.

BEGIN_EVENT_MAP(CGTFPOSCommCtrl, COleControl)
END_EVENT_MAP()



// �Ӽ� �������Դϴ�.

// TODO: �ʿ信 ���� �Ӽ� �������� �߰��մϴ�. ī��Ʈ�� �̿� ���� �����ؾ� �մϴ�.
BEGIN_PROPPAGEIDS(CGTFPOSCommCtrl, 1)
	PROPPAGEID(CGTFPOSCommPropPage::guid)
END_PROPPAGEIDS(CGTFPOSCommCtrl)



// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CGTFPOSCommCtrl, "GTFPOSCOMM.GTFPOSCommCtrl.1",
	0x45d79fa2, 0x341, 0x4aa3, 0xb3, 0x1a, 0xe3, 0xcb, 0x37, 0x83, 0x3b, 0xdd)



// ���� ���̺귯�� ID�� �����Դϴ�.

IMPLEMENT_OLETYPELIB(CGTFPOSCommCtrl, _tlid, _wVerMajor, _wVerMinor)



// �������̽� ID�Դϴ�.

const IID IID_DGTFPOSComm = { 0xC9E948B8, 0xCF0D, 0x4E62, { 0xAB, 0xB, 0xB, 0x7D, 0xE7, 0xA7, 0xBE, 0x3D } };
const IID IID_DGTFPOSCommEvents = { 0x9F2AEF6, 0x14BC, 0x4CEE, { 0xA3, 0x1F, 0x57, 0x70, 0x89, 0x2A, 0x37, 0xD2 } };


// ��Ʈ�� ���� �����Դϴ�.

static const DWORD _dwGTFPOSCommOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CGTFPOSCommCtrl, IDS_GTFPOSCOMM, _dwGTFPOSCommOleMisc)



// CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::UpdateRegistry -
// CGTFPOSCommCtrl���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��Ʈ���� ����Ʈ �� ������ ��Ģ�� �ؼ��ϴ���
	// Ȯ���մϴ�. �ڼ��� ������ MFC Technical Note 64��
	// �����Ͻʽÿ�. ��Ʈ���� ����Ʈ �� ��Ģ��
	// ���� �ʴ� ��� �������� ���� ��° �Ű� ������ �����մϴ�.
	// afxRegApartmentThreading�� 0���� �����մϴ�.

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



// ���̼��� ���ڿ��Դϴ�.

static const TCHAR _szLicFileName[] = _T("GTFPOSComm.lic");

static const WCHAR _szLicString[] = L"Copyright (c) 2016 ";



// CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::VerifyUserLicense -
// �����  ���̼����� �ִ��� �˻��մϴ�.

BOOL CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}



// CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::GetLicenseKey -
// ��Ÿ��  ���̼��� Ű�� ��ȯ�մϴ�.

BOOL CGTFPOSCommCtrl::CGTFPOSCommCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR *pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


// CGTFPOSCommCtrl::CGTFPOSCommCtrl - �������Դϴ�.

CGTFPOSCommCtrl::CGTFPOSCommCtrl()
{
	InitializeIIDs(&IID_DGTFPOSComm, &IID_DGTFPOSCommEvents);
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �ʱ�ȭ�մϴ�.
	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	hIns = LoadLibrary(_T("C:\\works\\GTF_COMM_DLL32\\GTF_COMM_DLL32\\Release\\GTF_COMM_DLL32.dll"));
	//hIns = LoadLibrary(_T("C:\\works\\GTF_COMM_DLL32\\GTF_COMM_DLL32\\Debug\\GTF_COMM_DLL32.dll"));

	if( hIns == NULL ) {
		printf("Load Library fail\n");
		
	}
	printf("Load End");

	fGTF_SetOffLineMode = (defGTF_SetOffLineMode)GetProcAddress( hIns, "GTF_SetOffLineMode" );
	fGTF_RequestApproval = (defGTF_RequestApproval)GetProcAddress( hIns, "GTF_RequestApproval" );

}



// CGTFPOSCommCtrl::~CGTFPOSCommCtrl - �Ҹ����Դϴ�.

CGTFPOSCommCtrl::~CGTFPOSCommCtrl()
{
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �����մϴ�.
}



// CGTFPOSCommCtrl::OnDraw - �׸��� �Լ��Դϴ�.

void CGTFPOSCommCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: ���� �ڵ带 ����ڰ� ���� �ۼ��� �׸��� �ڵ�� �ٲٽʽÿ�.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CGTFPOSCommCtrl::DoPropExchange - ���Ӽ� �����Դϴ�.

void CGTFPOSCommCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: �������� ����� ���� �Ӽ� ��ο� ���� PX_ functions�� ȣ���մϴ�.
}



// CGTFPOSCommCtrl::OnResetState - ��Ʈ���� �⺻ ���·� �ٽ� �����մϴ�.

void CGTFPOSCommCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange�� ��� �ִ� �⺻���� �ٽ� �����մϴ�.

	// TODO: ���⿡�� �ٸ� ��� ��Ʈ���� ���¸� �ٽ� �����մϴ�.
}



// CGTFPOSCommCtrl::AboutBox - "����" ��ȭ ���ڸ� ����ڿ��� ���� �ݴϴ�.

void CGTFPOSCommCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_GTFPOSCOMM);
	dlgAbout.DoModal();
}



// CGTFPOSCommCtrl �޽��� ó�����Դϴ�.


LONG CGTFPOSCommCtrl::GTF_RequestApproval(CHAR* P_Addr, LONG P_Port, CHAR* RequestMsg, LONG RequestLen, CHAR* RecvMsg, LONG ReadTimeOut)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: ���⿡ ����ġ ó���⸦ �߰��մϴ�.
	return fGTF_RequestApproval(P_Addr, P_Port, RequestMsg, RequestLen, RecvMsg, ReadTimeOut);

}


void CGTFPOSCommCtrl::GTF_SetOffLineMode(LONG Mode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: ���⿡ ����ġ ó���⸦ �߰��մϴ�.
	fGTF_SetOffLineMode(Mode);
}
