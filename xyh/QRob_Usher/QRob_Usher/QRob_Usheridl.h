

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Jun 16 23:42:39 2013
 */
/* Compiler settings for QRob_Usher.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __QRob_Usheridl_h__
#define __QRob_Usheridl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DQRob_Usher_FWD_DEFINED__
#define ___DQRob_Usher_FWD_DEFINED__
typedef interface _DQRob_Usher _DQRob_Usher;
#endif 	/* ___DQRob_Usher_FWD_DEFINED__ */


#ifndef ___DQRob_UsherEvents_FWD_DEFINED__
#define ___DQRob_UsherEvents_FWD_DEFINED__
typedef interface _DQRob_UsherEvents _DQRob_UsherEvents;
#endif 	/* ___DQRob_UsherEvents_FWD_DEFINED__ */


#ifndef __QRob_Usher_FWD_DEFINED__
#define __QRob_Usher_FWD_DEFINED__

#ifdef __cplusplus
typedef class QRob_Usher QRob_Usher;
#else
typedef struct QRob_Usher QRob_Usher;
#endif /* __cplusplus */

#endif 	/* __QRob_Usher_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __QRob_UsherLib_LIBRARY_DEFINED__
#define __QRob_UsherLib_LIBRARY_DEFINED__

/* library QRob_UsherLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_QRob_UsherLib;

#ifndef ___DQRob_Usher_DISPINTERFACE_DEFINED__
#define ___DQRob_Usher_DISPINTERFACE_DEFINED__

/* dispinterface _DQRob_Usher */
/* [uuid] */ 


EXTERN_C const IID DIID__DQRob_Usher;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("816048DA-D1E1-45D3-9F83-7C11C1D36FD4")
    _DQRob_Usher : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DQRob_UsherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DQRob_Usher * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DQRob_Usher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DQRob_Usher * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DQRob_Usher * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DQRob_Usher * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DQRob_Usher * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DQRob_Usher * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DQRob_UsherVtbl;

    interface _DQRob_Usher
    {
        CONST_VTBL struct _DQRob_UsherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DQRob_Usher_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DQRob_Usher_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DQRob_Usher_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DQRob_Usher_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DQRob_Usher_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DQRob_Usher_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DQRob_Usher_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DQRob_Usher_DISPINTERFACE_DEFINED__ */


#ifndef ___DQRob_UsherEvents_DISPINTERFACE_DEFINED__
#define ___DQRob_UsherEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DQRob_UsherEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DQRob_UsherEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("765C8152-2646-4792-B08E-8807F06D1C1A")
    _DQRob_UsherEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DQRob_UsherEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DQRob_UsherEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DQRob_UsherEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DQRob_UsherEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DQRob_UsherEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DQRob_UsherEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DQRob_UsherEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DQRob_UsherEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DQRob_UsherEventsVtbl;

    interface _DQRob_UsherEvents
    {
        CONST_VTBL struct _DQRob_UsherEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DQRob_UsherEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DQRob_UsherEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DQRob_UsherEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DQRob_UsherEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DQRob_UsherEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DQRob_UsherEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DQRob_UsherEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DQRob_UsherEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_QRob_Usher;

#ifdef __cplusplus

class DECLSPEC_UUID("89E57454-D37D-4021-B6CD-82E161670F79")
QRob_Usher;
#endif
#endif /* __QRob_UsherLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


