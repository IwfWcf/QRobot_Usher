#pragma once

// QRob_UsherCtrl.h : CQRob_UsherCtrl ActiveX �ؼ����������


// CQRob_UsherCtrl : �й�ʵ�ֵ���Ϣ������� QRob_UsherCtrl.cpp��

class CQRob_UsherCtrl : public COleControl
{
	DECLARE_DYNCREATE(CQRob_UsherCtrl)

// ���캯��
public:
	CQRob_UsherCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CQRob_UsherCtrl();

	DECLARE_OLECREATE_EX(CQRob_UsherCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CQRob_UsherCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CQRob_UsherCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CQRob_UsherCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
};

