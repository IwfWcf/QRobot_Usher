// QRob_UsherCtrl.cpp : CQRob_UsherCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "QRob_Usher.h"
#include "QRob_UsherCtrl.h"
#include "QRob_UsherPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRob_UsherCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CQRob_UsherCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CQRob_UsherCtrl, COleControl)
	DISP_FUNCTION_ID(CQRob_UsherCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CQRob_UsherCtrl, COleControl)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CQRob_UsherCtrl, 1)
	PROPPAGEID(CQRob_UsherPropPage::guid)
END_PROPPAGEIDS(CQRob_UsherCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CQRob_UsherCtrl, "QROB_USHER.QRob_UsherCtrl.1",
	0x89e57454, 0xd37d, 0x4021, 0xb6, 0xcd, 0x82, 0xe1, 0x61, 0x67, 0xf, 0x79)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CQRob_UsherCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID IID_DQRob_Usher = { 0x816048DA, 0xD1E1, 0x45D3, { 0x9F, 0x83, 0x7C, 0x11, 0xC1, 0xD3, 0x6F, 0xD4 } };
const IID IID_DQRob_UsherEvents = { 0x765C8152, 0x2646, 0x4792, { 0xB0, 0x8E, 0x88, 0x7, 0xF0, 0x6D, 0x1C, 0x1A } };


// 控件类型信息

static const DWORD _dwQRob_UsherOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CQRob_UsherCtrl, IDS_QROB_USHER, _dwQRob_UsherOleMisc)



// CQRob_UsherCtrl::CQRob_UsherCtrlFactory::UpdateRegistry -
// 添加或移除 CQRob_UsherCtrl 的系统注册表项

BOOL CQRob_UsherCtrl::CQRob_UsherCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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



// CQRob_UsherCtrl::CQRob_UsherCtrl - 构造函数

CQRob_UsherCtrl::CQRob_UsherCtrl()
{
	InitializeIIDs(&IID_DQRob_Usher, &IID_DQRob_UsherEvents);
	// TODO: 在此初始化控件的实例数据。
}



// CQRob_UsherCtrl::~CQRob_UsherCtrl - 析构函数

CQRob_UsherCtrl::~CQRob_UsherCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CQRob_UsherCtrl::OnDraw - 绘图函数

void CQRob_UsherCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CQRob_UsherCtrl::DoPropExchange - 持久性支持

void CQRob_UsherCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CQRob_UsherCtrl::OnResetState - 将控件重置为默认状态

void CQRob_UsherCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CQRob_UsherCtrl::AboutBox - 向用户显示“关于”框

void CQRob_UsherCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_QROB_USHER);
	dlgAbout.DoModal();
}



// CQRob_UsherCtrl 消息处理程序
