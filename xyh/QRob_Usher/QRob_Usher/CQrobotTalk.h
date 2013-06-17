// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "D:\\Program Files(study)\\Qrobot管理软件\\QrobotInterface.dll" no_namespace
// CQrobotTalk 包装类

class CQrobotTalk : public COleDispatchDriver
{
public:
	CQrobotTalk(){} // 调用 COleDispatchDriver 默认构造函数
	CQrobotTalk(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotTalk(const CQrobotTalk& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IQrobotTalk 方法
public:
	BOOL QroTalkInitial()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetRecordTime(long milTimes)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, milTimes);
	}
	BOOL StartRecognize(LPCTSTR strGrammName, BOOL flagSave)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strGrammName, flagSave);
		return result;
	}
	BOOL StopRecognize(LPCTSTR strPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPath);
		return result;
	}
	BOOL StartVoiceRecord()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL StopVoiceRecord(LPCTSTR strPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPath);
		return result;
	}
	BOOL IsRecognizeMatch(long * indexLocale, long * indexClound)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, indexLocale, indexClound);
		return result;
	}
	void DisposeCurrentReco()
	{
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ReleaseBuffer()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL IsRecognizeFinish()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetVoiceCloudGrammer(LPCTSTR strGrammer)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strGrammer);
	}
	BOOL OpenVoiceClound()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL CloseVoiceCloud()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL StartVoiceCloud()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL StopVoiceCloud()
	{
		BOOL result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetVoiceCloundModule(long moduler)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, moduler);
	}
	BOOL ChangScenceFile(LPCTSTR strScencePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strScencePath);
		return result;
	}
	void SetVoiceCloudDelay(long timeSleep)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, timeSleep);
	}

	// IQrobotTalk 属性
public:

};
