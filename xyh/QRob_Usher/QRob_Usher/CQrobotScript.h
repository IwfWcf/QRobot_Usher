// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "D:\\Program Files(study)\\Qrobot管理软件\\QrobotInterface.dll" no_namespace
// CQrobotScript 包装类

class CQrobotScript : public COleDispatchDriver
{
public:
	CQrobotScript(){} // 调用 COleDispatchDriver 默认构造函数
	CQrobotScript(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotScript(const CQrobotScript& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IQrobotScript 方法
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

	// IQrobotScript 属性
public:

};
