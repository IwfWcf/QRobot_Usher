#pragma once

// QRob_UsherCtrl.h : CQRob_UsherCtrl ActiveX 控件类的声明。


// CQRob_UsherCtrl : 有关实现的信息，请参阅 QRob_UsherCtrl.cpp。

class CQRob_UsherCtrl : public COleControl
{
	DECLARE_DYNCREATE(CQRob_UsherCtrl)

// 构造函数
public:
	CQRob_UsherCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CQRob_UsherCtrl();

	DECLARE_OLECREATE_EX(CQRob_UsherCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CQRob_UsherCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CQRob_UsherCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CQRob_UsherCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
	};
};

