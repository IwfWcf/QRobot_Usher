// QRob_UsherPropPage.cpp : CQRob_UsherPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "QRob_Usher.h"
#include "QRob_UsherPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRob_UsherPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CQRob_UsherPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CQRob_UsherPropPage, "QROB_USHER.QRob_UsherPropPage.1",
	0xd86e1317, 0x7cc3, 0x4d84, 0xb7, 0x29, 0x75, 0xea, 0x49, 0xc8, 0xd8, 0x65)



// CQRob_UsherPropPage::CQRob_UsherPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CQRob_UsherPropPage ��ϵͳע�����

BOOL CQRob_UsherPropPage::CQRob_UsherPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_QROB_USHER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CQRob_UsherPropPage::CQRob_UsherPropPage - ���캯��

CQRob_UsherPropPage::CQRob_UsherPropPage() :
	COlePropertyPage(IDD, IDS_QROB_USHER_PPG_CAPTION)
{
}



// CQRob_UsherPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CQRob_UsherPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CQRob_UsherPropPage ��Ϣ�������
