// DlgMain.cpp : implementation file
//

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "DlgMain.h"
#include "CQrobotController.h"
#include <atlsafe.h>
#include <iostream> 
#include <fstream>
using namespace std;
// CDlgMain dialog

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
//	DDX_Control(pDX, IDC_QROBOTEVENTCTRL1, m_eventCtrl);
}


BEGIN_MESSAGE_MAP(CDlgMain, CDialog)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlgMain message handlers
BEGIN_EVENTSINK_MAP(CDlgMain, CDialog)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 1, CDlgMain::InitModuleQroboteventctrl1, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 2, CDlgMain::CreateModuleWindowQroboteventctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	//ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 4, CDlgMain::CloudVoiceCmdQroboteventctrl1, VTS_I4 VTS_BSTR)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 6, CDlgMain::ExitModuleQroboteventctrl1, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 5, CDlgMain::DestroyModuleWindowQroboteventctrl1, VTS_NONE)
	//ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 5, CDlgMain::LineCommandQroboteventctrl1, VTS_BSTR)
	//ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 3, CDlgMain::LocaleVoiceCmdQroboteventctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 3, CDlgMain::QRobotMsgMotionQroboteventctrl1, VTS_I4 VTS_I4 VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 4, CDlgMain::QRobotMsgNormalQroboteventctrl1, VTS_I4 VTS_I4 VTS_PVARIANT)
	//ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 8, CDlgMain::QRobotMsgVoiceQroboteventctrl1, VTS_I4 VTS_I4 VTS_PVARIANT)
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

void CDlgMain::InitModuleQroboteventctrl1()
{
	// TODO: Add your message handler code here
	
	if(!m_speak.CreateDispatch(_T("QrobotInterface.Speak.1")))
	{
		AfxMessageBox(_T("Create Dispach Failed"));
	}
	m_speak.QroSpeakInitial();//语音识别初始化

	if(!m_Talk.CreateDispatch(_T("QrobotInterface.Talk.1")))
	{
		AfxMessageBox(_T("TALK Create Dispach Failed"));
	}
	m_Talk.QroTalkInitial();//语音识别初始化
	m_Script.CreateDispatch(_T("QrobotInterface.Script.1"));
	
	
}

void CDlgMain::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgMain::CreateModuleWindowQroboteventctrl1(long top, long left, long width, long height)
{
	// TODO: Add your message handler code here
	//int timeCloudDelay = 6000;
  //  int recordWaitTime = 20000;
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
	m_speak.AddTextToPlayList(_T("当前是测试模式"), _T(""), TRUE);//添加文本到播放列表
	m_speak.StartAsynPlay();//更新播放列表并播放文件

//	play("稍后");
	//显示新的对话框
	if(!funcDlg.m_hWnd){
		funcDlg.Create(IDD_FUNCDLG);
	}
	funcDlg.ShowWindow(SW_SHOW);

	
}

//void CDlgMain::CloudVoiceCmdQroboteventctrl1(long msgType, LPCTSTR strResult)
/////{
	
//}

void CDlgMain::ExitModuleQroboteventctrl1()
{
	// TODO: Add your message handler code here
	funcDlg.DestroyWindow();//关闭非模式窗口
	return;
}

void CDlgMain::DestroyModuleWindowQroboteventctrl1()
{
	// TODO: Add your message handler code here
	return;
}

//void CDlgMain::LineCommandQroboteventctrl1(LPCTSTR strResult)
//{
	// TODO: Add your message handler code here
//}

/*void CDlgMain::LocaleVoiceCmdQroboteventctrl1(long msgType, long sentenceID, long matchScore, long slotNum, VARIANT* slotID, VARIANT* slotText)
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
}*/
//yao
void CDlgMain::QRobotMsgMotionQroboteventctrl1(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
	/*switch(static_cast<MotioMsg>(nMsgID))
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
	}*/
	return ;
}

void CDlgMain::QRobotMsgNormalQroboteventctrl1(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
}
/*
void CDlgMain::QRobotMsgVoiceQroboteventctrl1(long nMsgID, long param1, VARIANT* param2)
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

}*/
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


void CDlgMain::play(char* c){
	string filename = "C:\\Users\\jie\\Desktop\\映射表.txt" ;
	fstream out; 
	char s[100][256] ;
	int i=0;
	out.open(filename,ios::in); 
	while(!out.eof()) 
	{ 
		out.getline(s[i],256,'\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束 
			i++;
	} 
	for(int j=0 ; j<i ; j=j+2){
		if(stricmp(s[j],c)==0){
	//		cout << s[j+1] << endl;
	//		string a;
			string a = "C:\\Users\\jie\\Desktop\\动作脚本\\对话\\";
			a = a+ s[j+1] ;
			RobotMove((CString)(a.c_str()));
			break;
		}
	}
	out.close(); 
	cin.get();//cin.get() 是用来读取回车键的,如果没这一行，输出的结果一闪就消失了
}

void CDlgMain::play(int s){
	switch(s){
		case 101 :         //点拍摄按钮的动作
			RobotMove(_T(".\\motion\\dance\\normal\\9.txt"));
			break ;
		case 102 :         //退出拍摄的动作
			RobotMove(_T(".\\motion\\dance\\normal\\9.txt"));
			break ;
		case 201 :          //点管理按钮的动作
			RobotMove(_T(".\\motion\\dance\\normal\\3.txt"));
			break ;
		case 202 :      //没30秒做一个动作
			RobotMove(_T(".\\motion\\dance\\normal\\3.txt"));
			break ;
		case 203 :        //退出管理的动作
			RobotMove(_T(".\\motion\\dance\\normal\\3.txt"));
			break ;
		case 301 :         //点对话按钮的动作
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 302 :         //关机
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 303 :         //稍后
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 304 :         //傲慢
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 305 :         //白眼
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 306 :         //鄙视
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 307 :         //擦汗
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 308 :         //哭
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 309 :         //大哭
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 310 :         //得意
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 311 :         //发呆
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 312 :         //晕
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 313 :         //发怒
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 314 :         //鼓掌
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 315 :         //哈欠
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 316 :         //欢笑
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 317 :         //惊恐
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 318 :         //可怜
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 319 :         //抠鼻
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 320 :         //流汗
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 321 :         //大红心
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 322 :         //眯
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 323 :         //钱
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 324 :         //正常
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 325 :         //亲亲
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 326 :         //溴大了
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 327 :         //悲伤
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 328 :         //大睡
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 329 :         //睡
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 330 :         //吓
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 331 :         //笑
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 332 :         //再见
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		default:
			;
	}
}

void CDlgMain::display(char * s){
}

int* CDlgMain::headposition(){




	HRESULT hr;
    CLSID QrobotControllerCSD={0};
    static CQrobotController m_comclass;
	if(LPDISPATCH(m_comclass)==NULL)
	{
	  hr = CLSIDFromProgID(_T("QrobotInterface.Controller.1"),&QrobotControllerCSD);
	if(SUCCEEDED(hr))
	{
	   LPDISPATCH pController = NULL; 
	   hr =::CoCreateInstance(	QrobotControllerCSD,NULL,CLSCTX_ALL,IID_IDispatch,(void**)&pController);
									ATLASSERT(SUCCEEDED(hr));
									m_comclass.AttachDispatch(pController);
	}
	else
	{TRACE("faile");}
	}


	m_comclass.UpdateMotorPosition();
	unsigned long * posArray = new unsigned long ;
	bool result = m_comclass.GetMotorPosition(posArray);
	if(result)
		{
	TRACE("bool 1\n");
	}
	else
	{
		TRACE("bool 0\n");
	}
	TRACE("%d\n",(BYTE)(*posArray));
	TRACE("%d\n",(BYTE)(*posArray>>8));

	RobotMove(_T("C:\\Users\\jie\\Desktop\\1.txt"));
	m_comclass.UpdateMotorPosition();
	bool result1 = m_comclass.GetMotorPosition(posArray);
	if(result1)
		{
	TRACE("bool 1\n");
	}
	else
	{
		TRACE("bool 0\n");
	}
	TRACE("%d\n",(BYTE)(*posArray));
	TRACE("%d\n",(BYTE)(*posArray>>8));


	



	int* i = new int[2];
	i[0] = 1 ;
	i[1] = 2 ;
	return i ;
}