#pragma once

// QRob_UsherPropPage.h : CQRob_UsherPropPage 属性页类的声明。


// CQRob_UsherPropPage : 有关实现的信息，请参阅 QRob_UsherPropPage.cpp。

class CQRob_UsherPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CQRob_UsherPropPage)
	DECLARE_OLECREATE_EX(CQRob_UsherPropPage)

// 构造函数
public:
	CQRob_UsherPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_QROB_USHER };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

