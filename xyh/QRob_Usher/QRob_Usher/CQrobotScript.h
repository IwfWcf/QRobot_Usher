// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\Program Files(study)\\Qrobot�������\\QrobotInterface.dll" no_namespace
// CQrobotScript ��װ��

class CQrobotScript : public COleDispatchDriver
{
public:
	CQrobotScript(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CQrobotScript(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotScript(const CQrobotScript& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IQrobotScript ����
public:
	BOOL OpenMotionFile(LPCTSTR strPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPath);
		return result;
	}
	BOOL AddMotionFile(LPCTSTR strPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPath);
		return result;
	}
	BOOL GetCompiledText()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void ClearAllCmds()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IQrobotScript ����
public:

};
