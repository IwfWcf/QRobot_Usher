// CDQrobotEvent.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDQrobotEvent

class CDQrobotEvent : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDQrobotEvent)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x2E1C5F29, 0x4AB2, 0x4AE5, { 0x9A, 0x48, 0xF8, 0x7A, 0xB8, 0x5, 0xFE, 0x4B } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:

// 操作
public:



};
