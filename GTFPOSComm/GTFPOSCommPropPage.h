#pragma once

// GTFPOSCommPropPage.h : CGTFPOSCommPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.


// CGTFPOSCommPropPage : ������ ������ GTFPOSCommPropPage.cpp��(��) �����Ͻʽÿ�.

class CGTFPOSCommPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CGTFPOSCommPropPage)
	DECLARE_OLECREATE_EX(CGTFPOSCommPropPage)

// �������Դϴ�.
public:
	CGTFPOSCommPropPage();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPPAGE_GTFPOSCOMM };

// �����Դϴ�.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �޽��� ���Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

