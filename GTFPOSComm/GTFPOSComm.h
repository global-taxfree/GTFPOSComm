#pragma once

// GTFPOSComm.h : GTFPOSComm.DLL�� �⺻ ��� �����Դϴ�.

#if !defined( __AFXCTL_H__ )
#error "�� ������ �����ϱ� ���� 'afxctl.h'�� �����Ͻʽÿ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CGTFPOSCommApp : ������ ������ GTFPOSComm.cpp�� �����Ͻʽÿ�.

class CGTFPOSCommApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

