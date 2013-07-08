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
	m_speak.QroSpeakInitial();//����ʶ���ʼ��

	if(!m_Talk.CreateDispatch(_T("QrobotInterface.Talk.1")))
	{
		AfxMessageBox(_T("TALK Create Dispach Failed"));
	}
	m_Talk.QroTalkInitial();//����ʶ���ʼ��
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
	m_speak.AddTextToPlayList(_T("��ǰ�ǲ���ģʽ"), _T(""), TRUE);//����ı��������б�
	m_speak.StartAsynPlay();//���²����б������ļ�

//	play("�Ժ�");
	//��ʾ�µĶԻ���
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
	funcDlg.DestroyWindow();//�رշ�ģʽ����
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
        strCommand = _T("ʶ����Ϊ��");//����δʶ��
    }
    else
    {
		strList.Attach(slotText->parray);
        for (int i = 0; i < slotNum; i++)
        {
            strCommand += strList[i];//������ʶ��
        }
    }
	//�ظ������ʼ¼��
	m_speak.StopAsynPlay();
	m_speak.ClearPlayList();
	m_speak.AddTextToPlayList(strCommand, strCommand, FALSE);
	m_speak.AddRecToPlayList();
	m_speak.StartAsynPlay();
    //�˶�һ��       
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
              RobotMove(_T(".\\motion\\statechange\\ֹͣ¼��.txt"));
        }
        break;
    case MSG_RECORD_BEGIN:
        {
            RobotMove(_T(".\\motion\\statechange\\��̬�´����Դ���ָ����ȡ״̬.txt"));
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
	string filename = "C:\\Users\\jie\\Desktop\\ӳ���.txt" ;
	fstream out; 
	char s[100][256] ;
	int i=0;
	out.open(filename,ios::in); 
	while(!out.eof()) 
	{ 
		out.getline(s[i],256,'\n');//getline(char *,int,char) ��ʾ�����ַ��ﵽ256�����������оͽ��� 
			i++;
	} 
	for(int j=0 ; j<i ; j=j+2){
		if(stricmp(s[j],c)==0){
	//		cout << s[j+1] << endl;
	//		string a;
			string a = "C:\\Users\\jie\\Desktop\\�����ű�\\�Ի�\\";
			a = a+ s[j+1] ;
			RobotMove((CString)(a.c_str()));
			break;
		}
	}
	out.close(); 
	cin.get();//cin.get() ��������ȡ�س�����,���û��һ�У�����Ľ��һ������ʧ��
}

void CDlgMain::play(int s){
	switch(s){
		case 101 :         //�����㰴ť�Ķ���
			RobotMove(_T(".\\motion\\dance\\normal\\9.txt"));
			break ;
		case 102 :         //�˳�����Ķ���
			RobotMove(_T(".\\motion\\dance\\normal\\9.txt"));
			break ;
		case 201 :          //�����ť�Ķ���
			RobotMove(_T(".\\motion\\dance\\normal\\3.txt"));
			break ;
		case 202 :      //û30����һ������
			RobotMove(_T(".\\motion\\dance\\normal\\3.txt"));
			break ;
		case 203 :        //�˳�����Ķ���
			RobotMove(_T(".\\motion\\dance\\normal\\3.txt"));
			break ;
		case 301 :         //��Ի���ť�Ķ���
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 302 :         //�ػ�
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 303 :         //�Ժ�
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 304 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 305 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 306 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 307 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 308 :         //��
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 309 :         //���
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 310 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 311 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 312 :         //��
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 313 :         //��ŭ
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 314 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 315 :         //��Ƿ
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 316 :         //��Ц
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 317 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 318 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 319 :         //�ٱ�
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 320 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 321 :         //�����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 322 :         //��
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 323 :         //Ǯ
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 324 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 325 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 326 :         //�����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 327 :         //����
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 328 :         //��˯
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 329 :         //˯
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 330 :         //��
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 331 :         //Ц
			RobotMove(_T(".\\motion\\dance\\normal\\11.txt"));
			break ;
		case 332 :         //�ټ�
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