#pragma once

// QRob_UsherPropPage.h : CQRob_UsherPropPage ����ҳ���������


// CQRob_UsherPropPage : �й�ʵ�ֵ���Ϣ������� QRob_UsherPropPage.cpp��

class CQRob_UsherPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CQRob_UsherPropPage)
	DECLARE_OLECREATE_EX(CQRob_UsherPropPage)

// ���캯��
public:
	CQRob_UsherPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_QROB_USHER };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

