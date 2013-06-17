// DlgMain.cpp : 实现文件
//

#include "stdafx.h"
#include "QRob_Usher.h"
#include "DlgMain.h"
#include "afxdialogex.h"
#include <atlsafe.h>

// CDlgMain 对话框

IMPLEMENT_DYNAMIC(CDlgMain, CDialog)

CDlgMain::CDlgMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMain::IDD, pParent)
{

}

CDlgMain::~CDlgMain()
{
}

void CDlgMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMain, CDialog)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CDlgMain 消息处理程序
BEGIN_EVENTSINK_MAP(CDlgMain, CDialog)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 1, CDlgMain::InitModuleQrobotEvent, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 2, CDlgMain::CreateModuleWindowQrobotEvent, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 4, CDlgMain::CloudVoiceCmdQrobotEvent, VTS_I4 VTS_BSTR)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 10, CDlgMain::ExitModuleQrobotEvent, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 9, CDlgMain::DestroyModuleWindowQrobotEvent, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 5, CDlgMain::LineCommandQrobotEvent, VTS_BSTR)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 3, CDlgMain::LocaleVoiceCmdQrobotEvent, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 7, CDlgMain::QRobotMsgMotionQrobotEvent, VTS_I4 VTS_I4 VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 6, CDlgMain::QRobotMsgNormalQrobotEvent, VTS_I4 VTS_I4 VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENT, 8, CDlgMain::QRobotMsgVoiceQrobotEvent, VTS_I4 VTS_I4 VTS_PVARIANT)
END_EVENTSINK_MAP()


int CDlgMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	// TODO:  Add your specialized creation code here
//	m_eventCtrl.MoveWindow(CRect(0,0,0,0));
	return 0;
}

void CDlgMain::InitModuleQrobotEvent()
{
	// TODO: Add your message handler code here
	if(!m_speak.CreateDispatch(_T("QrobotInterface.Speak.1")))
	{
		AfxMessageBox(_T("Create Dispach Failed"));
	}
	m_speak.QroSpeakInitial();

	if(!m_Talk.CreateDispatch(_T("QrobotInterface.Talk.1")))
	{
		AfxMessageBox(_T("TALK Create Dispach Failed"));
	}
	m_Talk.QroTalkInitial();
	m_Script.CreateDispatch(_T("QrobotInterface.Script.1"));
}



void CDlgMain::CreateModuleWindowQrobotEvent(long top, long left, long width, long height)
{
	// TODO: Add your message handler code here
	int timeCloudDelay = 6000;
    int recordWaitTime = 20000;
// 	LPCTSTR sceneFileName = _T("normal.xml");
// 	m_Talk.SetRecordTime(recordWaitTime);
// 
// 	if(!m_Talk.ChangScenceFile(sceneFileName))
// 	{
// 		
// 	}
// 	else
// 	{
// 		m_Talk.SetVoiceCloundModule(CLOUND_NORMAL);
// 		m_Talk.SetVoiceCloudDelay(timeCloudDelay);
// 		m_Talk.OpenVoiceClound();
// 	}
	//m_speak.StopAsynPlay();
	//m_speak.ClearPlayList();
	m_speak.AddTextToPlayList(_T("当前是测试模式"), _T(""), TRUE);
	m_speak.StartAsynPlay();
}

void CDlgMain::CloudVoiceCmdQrobotEvent(long msgType, LPCTSTR strResult)
{
	
}

void CDlgMain::ExitModuleQrobotEvent()
{
	// TODO: Add your message handler code here
	return;
}

void CDlgMain::DestroyModuleWindowQrobotEvent()
{
	// TODO: Add your message handler code here
	return;
}

void CDlgMain::LineCommandQrobotEvent(LPCTSTR strResult)
{
	// TODO: Add your message handler code here
}

void CDlgMain::LocaleVoiceCmdQrobotEvent(long msgType, long sentenceID, long matchScore, long slotNum, VARIANT* slotID, VARIANT* slotText)
{
	// TODO: Add your message handler code here
	CString strCommand;
	CComSafeArray<BSTR> strList;
	
	if (slotNum <= 0)
    {
        strCommand = _T("识别结果为空");//语音未识别
    }
    else
    {
		strList.Attach(slotText->parray);
        for (int i = 0; i < slotNum; i++)
        {
            strCommand += strList[i];//语音已识别
        }
    }
	//重复话语，开始录音
	m_speak.StopAsynPlay();
	m_speak.ClearPlayList();
	m_speak.AddTextToPlayList(strCommand, strCommand, FALSE);
	m_speak.AddRecToPlayList();
	m_speak.StartAsynPlay();
    //运动一次       
	RobotMove(_T(".\\motion\\dance\\normal\\1.txt"));
}

void CDlgMain::QRobotMsgMotionQrobotEvent(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
	switch(static_cast<MotioMsg>(nMsgID))
	{
	case HEAD_TOUCH_DOWM:
		if (!m_Talk.IsRecognizeFinish())
		{
			m_Talk.DisposeCurrentReco();
		}
		break;
	case HEAD_TOUCH_UP:
		m_Talk.StartRecognize(_T("QQRobot"), FALSE);
		break;
	default:
		return;
	}
}

void CDlgMain::QRobotMsgNormalQrobotEvent(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
}

void CDlgMain::QRobotMsgVoiceQrobotEvent(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
	switch(static_cast<VoiceMsg>(nMsgID))
	{
    case MSG_RECORD_FINISHED:
        {
              RobotMove(_T(".\\motion\\statechange\\停止录音.txt"));
        }
        break;
    case MSG_RECORD_BEGIN:
        {
            RobotMove(_T(".\\motion\\statechange\\常态下触摸脑袋，指令听取状态.txt"));
        }
        break;
    case MSG_PLAY_READYFLAG:
        {

        }
        break;
    case MSG_PLAY_ASYNCSTART:
        {
//            string strParam = (string)e.param2;
//            Console.WriteLine("Begin Speak Text:{0}\n", strParam);
        }
        break;
    case MSG_PLAY_ASYNCFINISH:
        {
//            string strParam = (string)e.param2;
//            Console.WriteLine("End Speak Text:{0}\n", strParam);
        }
        break;
    case MSG_PLAY_ASYNCSTOP:
        {
//            string strParam = (string)e.param2;
//            Console.WriteLine("Stop Speak Text\n");
        }
        break;
    case MSG_START_RECORD:
        {
            m_Talk.StartRecognize(_T("QQRobot"), FALSE);
        }
        break;
	}

}
BOOL CDlgMain::RobotMove(LPCTSTR strPath)
{
	HRESULT hr;	
	CLSID QrobotControllerCSD={0};
	static CQrobotController m_comclass;
	if(LPDISPATCH(m_comclass)==NULL)
	{
		hr = CLSIDFromProgID(_T("QrobotInterface.Controller.1"),&QrobotControllerCSD);
		if(SUCCEEDED(hr))
		{
			LPDISPATCH pController = NULL; 
			hr =::CoCreateInstance(	QrobotControllerCSD,
									NULL,
									CLSCTX_ALL,
									IID_IDispatch,
									(void**)&pController);
			ATLASSERT(SUCCEEDED(hr));
			m_comclass.AttachDispatch(pController);
		}
		else
			return FALSE;
	}
	if(!m_Script.OpenMotionFile(strPath))
	{
		return FALSE;
	}
	else
	{
		if(m_Script.GetCompiledText())
		{
			m_comclass.SetMotionCtrl(LPUNKNOWN(m_Script));
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;

}


