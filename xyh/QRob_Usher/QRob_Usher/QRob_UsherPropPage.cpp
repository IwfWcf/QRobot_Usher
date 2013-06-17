// QRob_UsherPropPage.cpp : CQRob_UsherPropPage 属性页类的实现。

#include "stdafx.h"
#include "QRob_Usher.h"
#include "QRob_UsherPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRob_UsherPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CQRob_UsherPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CQRob_UsherPropPage, "QROB_USHER.QRob_UsherPropPage.1",
	0xd86e1317, 0x7cc3, 0x4d84, 0xb7, 0x29, 0x75, 0xea, 0x49, 0xc8, 0xd8, 0x65)



// CQRob_UsherPropPage::CQRob_UsherPropPageFactory::UpdateRegistry -
// 添加或移除 CQRob_UsherPropPage 的系统注册表项

BOOL CQRob_UsherPropPage::CQRob_UsherPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_QROB_USHER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CQRob_UsherPropPage::CQRob_UsherPropPage - 构造函数

CQRob_UsherPropPage::CQRob_UsherPropPage() :
	COlePropertyPage(IDD, IDS_QROB_USHER_PPG_CAPTION)
{
}



// CQRob_UsherPropPage::DoDataExchange - 在页和属性间移动数据

void CQRob_UsherPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CQRob_UsherPropPage 消息处理程序
