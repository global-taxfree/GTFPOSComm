#pragma once

// GTFPOSCommCtrl.h : CGTFPOSCommCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.


// CGTFPOSCommCtrl : ������ ������ GTFPOSCommCtrl.cpp��(��) �����Ͻʽÿ�.

class CGTFPOSCommCtrl : public COleControl
{
	DECLARE_DYNCREATE(CGTFPOSCommCtrl)

// �������Դϴ�.
public:
	CGTFPOSCommCtrl();

	HINSTANCE hIns; // DLL Import��

	typedef void (*defGTF_SetOffLineMode)(int Mode);
	defGTF_SetOffLineMode fGTF_SetOffLineMode; 
	
	typedef int (*defGTF_RequestApproval)(char *P_Addr, int P_Port, char *RequestMsg, int RequestLen,char *RecvMsg,int ReadTimeOut);
	defGTF_RequestApproval fGTF_RequestApproval; 

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// �����Դϴ�.
protected:
	~CGTFPOSCommCtrl();

	BEGIN_OLEFACTORY(CGTFPOSCommCtrl)        // Ŭ���� ���͸��� GUID�Դϴ�.
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR *);
	END_OLEFACTORY(CGTFPOSCommCtrl)

	DECLARE_OLETYPELIB(CGTFPOSCommCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CGTFPOSCommCtrl)     // �Ӽ� ������ ID�Դϴ�.
	DECLARE_OLECTLTYPE(CGTFPOSCommCtrl)		// ���� �̸��� ��Ÿ �����Դϴ�.

// �޽��� ���Դϴ�.
	DECLARE_MESSAGE_MAP()

// ����ġ ���Դϴ�.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �̺�Ʈ ���Դϴ�.
	DECLARE_EVENT_MAP()

// ����ġ�� �̺�Ʈ ID�Դϴ�.
public:
	enum {
		dispidGTF_SetOffLineMode = 2L,
		dispidGTF_RequestApproval = 1L
	};
protected:
	LONG GTF_RequestApproval(CHAR* P_Addr, LONG P_Port, CHAR* RequestMsg, LONG RequestLen, CHAR* RecvMsg, LONG ReadTimeOut);
	void GTF_SetOffLineMode(LONG Mode);
};

