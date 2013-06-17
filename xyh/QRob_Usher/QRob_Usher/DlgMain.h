#pragma once
#include "CQrobotSpeak.h"
#include "CQrobotTalk.h"
#include "CDQrobotEvent.h"
#include "CQrobotController.h"
#include "CQrobotScript.h"



// CDlgMain �Ի���

class CDlgMain : public CDialog
{
	DECLARE_DYNAMIC(CDlgMain)

public:
	enum CloundMode
	{
		CLOUND_NORMAL = 0x01,
        ClOUND_CHILD = 0x02,
        CLOUND_QQMUSIC = 0x03,
        CLOUND_STOCK = 0x04,
        CLOUND_DEFMUSIC = 0x05,
	};
	enum VoiceMsg
	{
		MSG_RECORD_FINISHED = 0x02,     //����¼������
        MSG_RECORD_BEGIN = 0x03,     //��ʼ¼������

        MSG_PLAY_READYFLAG = 0x14,     //���������źţ�1:��ʼ��0:����
        MSG_PLAY_ASYNCSTART = 0x15,     //ͬ�����������У���������������
        MSG_PLAY_ASYNCFINISH = 0x16,    //�첽�����������	
        MSG_PLAY_ASYNCSTOP = 0x17,     //�첽�����ж�
        MSG_START_RECORD = 0x18      //��ʼ¼��
	};
	enum MotioMsg
	{
        HEAD_TOUCH_DOWM = 0x01,
        HEAD_TOUCH_UP = 0x02,
        HEAD_LONG_TOUCH = 0x03,
        NECK_TOUCH_DOWN = 0x04,
        NECK_TOUCH_UP = 0x05
	};

	CDlgMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMain();

// �Ի�������
	enum { IDD = IDD_DLGMAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	DECLARE_EVENTSINK_MAP()
	void InitModuleQrobotEvent();
	//CDQrobotEvent m_eventCtrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void CreateModuleWindowQrobotEvent(long top, long left, long width, long height);
	void CloudVoiceCmdQrobotEvent(long msgType, LPCTSTR strResult);
	void ExitModuleQrobotEvent();
	void DestroyModuleWindowQrobotEvent();
	void LineCommandQrobotEvent(LPCTSTR strResult);
	void LocaleVoiceCmdQrobotEvent(long msgType, long sentenceID, long matchScore, long slotNum, VARIANT* slotID, VARIANT* slotText);
	void QRobotMsgMotionQrobotEvent(long nMsgID, long param1, VARIANT* param2);
	void QRobotMsgNormalQrobotEvent(long nMsgID, long param1, VARIANT* param2);
	void QRobotMsgVoiceQrobotEvent(long nMsgID, long param1, VARIANT* param2);
	CQrobotTalk m_Talk;
	BOOL RobotMove(LPCTSTR);
	CQrobotScript m_Script;
	CQrobotSpeak m_speak;

};
