// GTFPOSCommPropPage.cpp : CGTFPOSCommPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "GTFPOSComm.h"
#include "GTFPOSCommPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CGTFPOSCommPropPage, COlePropertyPage)



// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CGTFPOSCommPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CGTFPOSCommPropPage, "GTFPOSCOMM.GTFPOSCommPropPage.1",
	0x49c17907, 0xb820, 0x427e, 0xab, 0x8f, 0x16, 0xd5, 0x55, 0x78, 0x2f, 0x5e)



// CGTFPOSCommPropPage::CGTFPOSCommPropPageFactory::UpdateRegistry -
// CGTFPOSCommPropPage���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CGTFPOSCommPropPage::CGTFPOSCommPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_GTFPOSCOMM_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CGTFPOSCommPropPage::CGTFPOSCommPropPage - �������Դϴ�.

CGTFPOSCommPropPage::CGTFPOSCommPropPage() :
	COlePropertyPage(IDD, IDS_GTFPOSCOMM_PPG_CAPTION)
{
}



// CGTFPOSCommPropPage::DoDataExchange - �������� �Ӽ� ���̿��� �����͸� �̵���ŵ�ϴ�.

void CGTFPOSCommPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CGTFPOSCommPropPage �޽��� ó�����Դϴ�.
