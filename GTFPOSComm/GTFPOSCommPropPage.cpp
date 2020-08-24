// GTFPOSCommPropPage.cpp : CGTFPOSCommPropPage 속성 페이지 클래스의 구현입니다.

#include "stdafx.h"
#include "GTFPOSComm.h"
#include "GTFPOSCommPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CGTFPOSCommPropPage, COlePropertyPage)



// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CGTFPOSCommPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CGTFPOSCommPropPage, "GTFPOSCOMM.GTFPOSCommPropPage.1",
	0x49c17907, 0xb820, 0x427e, 0xab, 0x8f, 0x16, 0xd5, 0x55, 0x78, 0x2f, 0x5e)



// CGTFPOSCommPropPage::CGTFPOSCommPropPageFactory::UpdateRegistry -
// CGTFPOSCommPropPage에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CGTFPOSCommPropPage::CGTFPOSCommPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_GTFPOSCOMM_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CGTFPOSCommPropPage::CGTFPOSCommPropPage - 생성자입니다.

CGTFPOSCommPropPage::CGTFPOSCommPropPage() :
	COlePropertyPage(IDD, IDS_GTFPOSCOMM_PPG_CAPTION)
{
}



// CGTFPOSCommPropPage::DoDataExchange - 페이지와 속성 사이에서 데이터를 이동시킵니다.

void CGTFPOSCommPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CGTFPOSCommPropPage 메시지 처리기입니다.
