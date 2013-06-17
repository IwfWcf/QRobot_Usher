// QRob_UsherCtrl.cpp : CQRob_UsherCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "QRob_Usher.h"
#include "QRob_UsherCtrl.h"
#include "QRob_UsherPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRob_UsherCtrl, COleControl)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CQRob_UsherCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CQRob_UsherCtrl, COleControl)
	DISP_FUNCTION_ID(CQRob_UsherCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CQRob_UsherCtrl, COleControl)
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CQRob_UsherCtrl, 1)
	PROPPAGEID(CQRob_UsherPropPage::guid)
END_PROPPAGEIDS(CQRob_UsherCtrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CQRob_UsherCtrl, "QROB_USHER.QRob_UsherCtrl.1",
	0x89e57454, 0xd37d, 0x4021, 0xb6, 0xcd, 0x82, 0xe1, 0x61, 0x67, 0xf, 0x79)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CQRob_UsherCtrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID IID_DQRob_Usher = { 0x816048DA, 0xD1E1, 0x45D3, { 0x9F, 0x83, 0x7C, 0x11, 0xC1, 0xD3, 0x6F, 0xD4 } };
const IID IID_DQRob_UsherEvents = { 0x765C8152, 0x2646, 0x4792, { 0xB0, 0x8E, 0x88, 0x7, 0xF0, 0x6D, 0x1C, 0x1A } };


// �ؼ�������Ϣ

static const DWORD _dwQRob_UsherOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CQRob_UsherCtrl, IDS_QROB_USHER, _dwQRob_UsherOleMisc)



// CQRob_UsherCtrl::CQRob_UsherCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CQRob_UsherCtrl ��ϵͳע�����

BOOL CQRob_UsherCtrl::CQRob_UsherCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_QROB_USHER,
			IDB_QROB_USHER,
			afxRegApartmentThreading,
			_dwQRob_UsherOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CQRob_UsherCtrl::CQRob_UsherCtrl - ���캯��

CQRob_UsherCtrl::CQRob_UsherCtrl()
{
	InitializeIIDs(&IID_DQRob_Usher, &IID_DQRob_UsherEvents);
	// TODO: �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}



// CQRob_UsherCtrl::~CQRob_UsherCtrl - ��������

CQRob_UsherCtrl::~CQRob_UsherCtrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}



// CQRob_UsherCtrl::OnDraw - ��ͼ����

void CQRob_UsherCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CQRob_UsherCtrl::DoPropExchange - �־���֧��

void CQRob_UsherCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}



// CQRob_UsherCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CQRob_UsherCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}



// CQRob_UsherCtrl::AboutBox - ���û���ʾ�����ڡ���

void CQRob_UsherCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_QROB_USHER);
	dlgAbout.DoModal();
}



// CQRob_UsherCtrl ��Ϣ�������
