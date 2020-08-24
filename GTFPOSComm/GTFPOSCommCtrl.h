#pragma once

// GTFPOSCommCtrl.h : CGTFPOSCommCtrl ActiveX 컨트롤 클래스의 선언입니다.


// CGTFPOSCommCtrl : 구현을 보려면 GTFPOSCommCtrl.cpp을(를) 참조하십시오.

class CGTFPOSCommCtrl : public COleControl
{
	DECLARE_DYNCREATE(CGTFPOSCommCtrl)

// 생성자입니다.
public:
	CGTFPOSCommCtrl();

	HINSTANCE hIns; // DLL Import용

	typedef void (*defGTF_SetOffLineMode)(int Mode);
	defGTF_SetOffLineMode fGTF_SetOffLineMode; 
	
	typedef int (*defGTF_RequestApproval)(char *P_Addr, int P_Port, char *RequestMsg, int RequestLen,char *RecvMsg,int ReadTimeOut);
	defGTF_RequestApproval fGTF_RequestApproval; 

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 구현입니다.
protected:
	~CGTFPOSCommCtrl();

	BEGIN_OLEFACTORY(CGTFPOSCommCtrl)        // 클래스 팩터리와 GUID입니다.
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR *);
	END_OLEFACTORY(CGTFPOSCommCtrl)

	DECLARE_OLETYPELIB(CGTFPOSCommCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CGTFPOSCommCtrl)     // 속성 페이지 ID입니다.
	DECLARE_OLECTLTYPE(CGTFPOSCommCtrl)		// 형식 이름과 기타 상태입니다.

// 메시지 맵입니다.
	DECLARE_MESSAGE_MAP()

// 디스패치 맵입니다.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 이벤트 맵입니다.
	DECLARE_EVENT_MAP()

// 디스패치와 이벤트 ID입니다.
public:
	enum {
		dispidGTF_SetOffLineMode = 2L,
		dispidGTF_RequestApproval = 1L
	};
protected:
	LONG GTF_RequestApproval(CHAR* P_Addr, LONG P_Port, CHAR* RequestMsg, LONG RequestLen, CHAR* RecvMsg, LONG ReadTimeOut);
	void GTF_SetOffLineMode(LONG Mode);
};

