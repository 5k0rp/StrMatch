
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0347 */
/* at Thu May 27 17:57:13 2004
 */
/* Compiler settings for ADDIN.IDL:
    Os, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ADDIN_h_h__
#define __ADDIN_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IInitDone_FWD_DEFINED__
#define __IInitDone_FWD_DEFINED__
typedef interface IInitDone IInitDone;
#endif 	/* __IInitDone_FWD_DEFINED__ */


#ifndef __IPropertyProfile_FWD_DEFINED__
#define __IPropertyProfile_FWD_DEFINED__
typedef interface IPropertyProfile IPropertyProfile;
#endif 	/* __IPropertyProfile_FWD_DEFINED__ */


#ifndef __IAsyncEvent_FWD_DEFINED__
#define __IAsyncEvent_FWD_DEFINED__
typedef interface IAsyncEvent IAsyncEvent;
#endif 	/* __IAsyncEvent_FWD_DEFINED__ */


#ifndef __ILanguageExtender_FWD_DEFINED__
#define __ILanguageExtender_FWD_DEFINED__
typedef interface ILanguageExtender ILanguageExtender;
#endif 	/* __ILanguageExtender_FWD_DEFINED__ */


#ifndef __IStatusLine_FWD_DEFINED__
#define __IStatusLine_FWD_DEFINED__
typedef interface IStatusLine IStatusLine;
#endif 	/* __IStatusLine_FWD_DEFINED__ */


#ifndef __AddIn_FWD_DEFINED__
#define __AddIn_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddIn AddIn;
#else
typedef struct AddIn AddIn;
#endif /* __cplusplus */

#endif 	/* __AddIn_FWD_DEFINED__ */


#ifndef __AddInConnection_FWD_DEFINED__
#define __AddInConnection_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddInConnection AddInConnection;
#else
typedef struct AddInConnection AddInConnection;
#endif /* __cplusplus */

#endif 	/* __AddInConnection_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IInitDone_INTERFACE_DEFINED__
#define __IInitDone_INTERFACE_DEFINED__

/* interface IInitDone */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IInitDone;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB634001-F13D-11d0-A459-004095E1DAEA")
    IInitDone : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IDispatch *pConnection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Done( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [out][in] */ SAFEARRAY * *pInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInitDoneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInitDone * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInitDone * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInitDone * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IInitDone * This,
            /* [in] */ IDispatch *pConnection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Done )( 
            IInitDone * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            IInitDone * This,
            /* [out][in] */ SAFEARRAY * *pInfo);
        
        END_INTERFACE
    } IInitDoneVtbl;

    interface IInitDone
    {
        CONST_VTBL struct IInitDoneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInitDone_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInitDone_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInitDone_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInitDone_Init(This,pConnection)	\
    (This)->lpVtbl -> Init(This,pConnection)

#define IInitDone_Done(This)	\
    (This)->lpVtbl -> Done(This)

#define IInitDone_GetInfo(This,pInfo)	\
    (This)->lpVtbl -> GetInfo(This,pInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInitDone_Init_Proxy( 
    IInitDone * This,
    /* [in] */ IDispatch *pConnection);


void __RPC_STUB IInitDone_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInitDone_Done_Proxy( 
    IInitDone * This);


void __RPC_STUB IInitDone_Done_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IInitDone_GetInfo_Proxy( 
    IInitDone * This,
    /* [out][in] */ SAFEARRAY * *pInfo);


void __RPC_STUB IInitDone_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInitDone_INTERFACE_DEFINED__ */


#ifndef __IPropertyProfile_INTERFACE_DEFINED__
#define __IPropertyProfile_INTERFACE_DEFINED__

/* interface IPropertyProfile */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPropertyProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB634002-F13D-11d0-A459-004095E1DAEA")
    IPropertyProfile : public IPropertyBag
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterProfileAs( 
            BSTR bstrProfileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyProfileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropertyProfile * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropertyProfile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropertyProfile * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IPropertyProfile * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT *pVar,
            /* [in] */ IErrorLog *pErrorLog);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IPropertyProfile * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ VARIANT *pVar);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterProfileAs )( 
            IPropertyProfile * This,
            BSTR bstrProfileName);
        
        END_INTERFACE
    } IPropertyProfileVtbl;

    interface IPropertyProfile
    {
        CONST_VTBL struct IPropertyProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyProfile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyProfile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyProfile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyProfile_Read(This,pszPropName,pVar,pErrorLog)	\
    (This)->lpVtbl -> Read(This,pszPropName,pVar,pErrorLog)

#define IPropertyProfile_Write(This,pszPropName,pVar)	\
    (This)->lpVtbl -> Write(This,pszPropName,pVar)


#define IPropertyProfile_RegisterProfileAs(This,bstrProfileName)	\
    (This)->lpVtbl -> RegisterProfileAs(This,bstrProfileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropertyProfile_RegisterProfileAs_Proxy( 
    IPropertyProfile * This,
    BSTR bstrProfileName);


void __RPC_STUB IPropertyProfile_RegisterProfileAs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPropertyProfile_INTERFACE_DEFINED__ */


#ifndef __IAsyncEvent_INTERFACE_DEFINED__
#define __IAsyncEvent_INTERFACE_DEFINED__

/* interface IAsyncEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAsyncEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ab634004-f13d-11d0-a459-004095e1daea")
    IAsyncEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEventBufferDepth( 
            long lDepth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventBufferDepth( 
            long *plDepth) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExternalEvent( 
            BSTR bstrSource,
            BSTR bstrMessage,
            BSTR bstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CleanBuffer( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAsyncEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAsyncEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAsyncEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAsyncEvent * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEventBufferDepth )( 
            IAsyncEvent * This,
            long lDepth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventBufferDepth )( 
            IAsyncEvent * This,
            long *plDepth);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExternalEvent )( 
            IAsyncEvent * This,
            BSTR bstrSource,
            BSTR bstrMessage,
            BSTR bstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CleanBuffer )( 
            IAsyncEvent * This);
        
        END_INTERFACE
    } IAsyncEventVtbl;

    interface IAsyncEvent
    {
        CONST_VTBL struct IAsyncEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAsyncEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAsyncEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAsyncEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAsyncEvent_SetEventBufferDepth(This,lDepth)	\
    (This)->lpVtbl -> SetEventBufferDepth(This,lDepth)

#define IAsyncEvent_GetEventBufferDepth(This,plDepth)	\
    (This)->lpVtbl -> GetEventBufferDepth(This,plDepth)

#define IAsyncEvent_ExternalEvent(This,bstrSource,bstrMessage,bstrData)	\
    (This)->lpVtbl -> ExternalEvent(This,bstrSource,bstrMessage,bstrData)

#define IAsyncEvent_CleanBuffer(This)	\
    (This)->lpVtbl -> CleanBuffer(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAsyncEvent_SetEventBufferDepth_Proxy( 
    IAsyncEvent * This,
    long lDepth);


void __RPC_STUB IAsyncEvent_SetEventBufferDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAsyncEvent_GetEventBufferDepth_Proxy( 
    IAsyncEvent * This,
    long *plDepth);


void __RPC_STUB IAsyncEvent_GetEventBufferDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAsyncEvent_ExternalEvent_Proxy( 
    IAsyncEvent * This,
    BSTR bstrSource,
    BSTR bstrMessage,
    BSTR bstrData);


void __RPC_STUB IAsyncEvent_ExternalEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAsyncEvent_CleanBuffer_Proxy( 
    IAsyncEvent * This);


void __RPC_STUB IAsyncEvent_CleanBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAsyncEvent_INTERFACE_DEFINED__ */


#ifndef __ILanguageExtender_INTERFACE_DEFINED__
#define __ILanguageExtender_INTERFACE_DEFINED__

/* interface ILanguageExtender */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILanguageExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AB634003-F13D-11d0-A459-004095E1DAEA")
    ILanguageExtender : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterExtensionAs( 
            /* [out][in] */ BSTR *bstrExtensionName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNProps( 
            /* [out][in] */ long *plProps) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindProp( 
            /* [in] */ BSTR bstrPropName,
            /* [out][in] */ long *plPropNum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropName( 
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
            /* [out][in] */ BSTR *pbstrPropName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPropVal( 
            /* [in] */ long lPropNum,
            /* [out][in] */ VARIANT *pvarPropVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPropVal( 
            /* [in] */ long lPropNum,
            /* [in] */ VARIANT *varPropVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropReadable( 
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropRead) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsPropWritable( 
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropWrite) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNMethods( 
            /* [out][in] */ long *plMethods) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindMethod( 
            BSTR bstrMethodName,
            /* [out][in] */ long *plMethodNum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMethodName( 
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
            /* [out][in] */ BSTR *pbstrMethodName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNParams( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ long *plParams) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParamDefValue( 
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
            /* [out][in] */ VARIANT *pvarParamDefValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE HasRetVal( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ BOOL *pboolRetValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CallAsProc( 
            /* [in] */ long lMethodNum,
            /* [in] */ SAFEARRAY * *paParams) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CallAsFunc( 
            /* [in] */ long lMethodNum,
            /* [out][in] */ VARIANT *pvarRetValue,
            /* [in] */ SAFEARRAY * *paParams) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILanguageExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILanguageExtender * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILanguageExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILanguageExtender * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterExtensionAs )( 
            ILanguageExtender * This,
            /* [out][in] */ BSTR *bstrExtensionName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNProps )( 
            ILanguageExtender * This,
            /* [out][in] */ long *plProps);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindProp )( 
            ILanguageExtender * This,
            /* [in] */ BSTR bstrPropName,
            /* [out][in] */ long *plPropNum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropName )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
            /* [out][in] */ BSTR *pbstrPropName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropVal )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [out][in] */ VARIANT *pvarPropVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPropVal )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [in] */ VARIANT *varPropVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropReadable )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropRead);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPropWritable )( 
            ILanguageExtender * This,
            /* [in] */ long lPropNum,
            /* [out][in] */ BOOL *pboolPropWrite);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNMethods )( 
            ILanguageExtender * This,
            /* [out][in] */ long *plMethods);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindMethod )( 
            ILanguageExtender * This,
            BSTR bstrMethodName,
            /* [out][in] */ long *plMethodNum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMethodName )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
            /* [out][in] */ BSTR *pbstrMethodName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNParams )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ long *plParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetParamDefValue )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
            /* [out][in] */ VARIANT *pvarParamDefValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *HasRetVal )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ BOOL *pboolRetValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CallAsProc )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [in] */ SAFEARRAY * *paParams);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CallAsFunc )( 
            ILanguageExtender * This,
            /* [in] */ long lMethodNum,
            /* [out][in] */ VARIANT *pvarRetValue,
            /* [in] */ SAFEARRAY * *paParams);
        
        END_INTERFACE
    } ILanguageExtenderVtbl;

    interface ILanguageExtender
    {
        CONST_VTBL struct ILanguageExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILanguageExtender_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILanguageExtender_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILanguageExtender_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILanguageExtender_RegisterExtensionAs(This,bstrExtensionName)	\
    (This)->lpVtbl -> RegisterExtensionAs(This,bstrExtensionName)

#define ILanguageExtender_GetNProps(This,plProps)	\
    (This)->lpVtbl -> GetNProps(This,plProps)

#define ILanguageExtender_FindProp(This,bstrPropName,plPropNum)	\
    (This)->lpVtbl -> FindProp(This,bstrPropName,plPropNum)

#define ILanguageExtender_GetPropName(This,lPropNum,lPropAlias,pbstrPropName)	\
    (This)->lpVtbl -> GetPropName(This,lPropNum,lPropAlias,pbstrPropName)

#define ILanguageExtender_GetPropVal(This,lPropNum,pvarPropVal)	\
    (This)->lpVtbl -> GetPropVal(This,lPropNum,pvarPropVal)

#define ILanguageExtender_SetPropVal(This,lPropNum,varPropVal)	\
    (This)->lpVtbl -> SetPropVal(This,lPropNum,varPropVal)

#define ILanguageExtender_IsPropReadable(This,lPropNum,pboolPropRead)	\
    (This)->lpVtbl -> IsPropReadable(This,lPropNum,pboolPropRead)

#define ILanguageExtender_IsPropWritable(This,lPropNum,pboolPropWrite)	\
    (This)->lpVtbl -> IsPropWritable(This,lPropNum,pboolPropWrite)

#define ILanguageExtender_GetNMethods(This,plMethods)	\
    (This)->lpVtbl -> GetNMethods(This,plMethods)

#define ILanguageExtender_FindMethod(This,bstrMethodName,plMethodNum)	\
    (This)->lpVtbl -> FindMethod(This,bstrMethodName,plMethodNum)

#define ILanguageExtender_GetMethodName(This,lMethodNum,lMethodAlias,pbstrMethodName)	\
    (This)->lpVtbl -> GetMethodName(This,lMethodNum,lMethodAlias,pbstrMethodName)

#define ILanguageExtender_GetNParams(This,lMethodNum,plParams)	\
    (This)->lpVtbl -> GetNParams(This,lMethodNum,plParams)

#define ILanguageExtender_GetParamDefValue(This,lMethodNum,lParamNum,pvarParamDefValue)	\
    (This)->lpVtbl -> GetParamDefValue(This,lMethodNum,lParamNum,pvarParamDefValue)

#define ILanguageExtender_HasRetVal(This,lMethodNum,pboolRetValue)	\
    (This)->lpVtbl -> HasRetVal(This,lMethodNum,pboolRetValue)

#define ILanguageExtender_CallAsProc(This,lMethodNum,paParams)	\
    (This)->lpVtbl -> CallAsProc(This,lMethodNum,paParams)

#define ILanguageExtender_CallAsFunc(This,lMethodNum,pvarRetValue,paParams)	\
    (This)->lpVtbl -> CallAsFunc(This,lMethodNum,pvarRetValue,paParams)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_RegisterExtensionAs_Proxy( 
    ILanguageExtender * This,
    /* [out][in] */ BSTR *bstrExtensionName);


void __RPC_STUB ILanguageExtender_RegisterExtensionAs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetNProps_Proxy( 
    ILanguageExtender * This,
    /* [out][in] */ long *plProps);


void __RPC_STUB ILanguageExtender_GetNProps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_FindProp_Proxy( 
    ILanguageExtender * This,
    /* [in] */ BSTR bstrPropName,
    /* [out][in] */ long *plPropNum);


void __RPC_STUB ILanguageExtender_FindProp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetPropName_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lPropNum,
    /* [in] */ long lPropAlias,
    /* [out][in] */ BSTR *pbstrPropName);


void __RPC_STUB ILanguageExtender_GetPropName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetPropVal_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lPropNum,
    /* [out][in] */ VARIANT *pvarPropVal);


void __RPC_STUB ILanguageExtender_GetPropVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_SetPropVal_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lPropNum,
    /* [in] */ VARIANT *varPropVal);


void __RPC_STUB ILanguageExtender_SetPropVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_IsPropReadable_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lPropNum,
    /* [out][in] */ BOOL *pboolPropRead);


void __RPC_STUB ILanguageExtender_IsPropReadable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_IsPropWritable_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lPropNum,
    /* [out][in] */ BOOL *pboolPropWrite);


void __RPC_STUB ILanguageExtender_IsPropWritable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetNMethods_Proxy( 
    ILanguageExtender * This,
    /* [out][in] */ long *plMethods);


void __RPC_STUB ILanguageExtender_GetNMethods_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_FindMethod_Proxy( 
    ILanguageExtender * This,
    BSTR bstrMethodName,
    /* [out][in] */ long *plMethodNum);


void __RPC_STUB ILanguageExtender_FindMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetMethodName_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lMethodNum,
    /* [in] */ long lMethodAlias,
    /* [out][in] */ BSTR *pbstrMethodName);


void __RPC_STUB ILanguageExtender_GetMethodName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetNParams_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lMethodNum,
    /* [out][in] */ long *plParams);


void __RPC_STUB ILanguageExtender_GetNParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_GetParamDefValue_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lMethodNum,
    /* [in] */ long lParamNum,
    /* [out][in] */ VARIANT *pvarParamDefValue);


void __RPC_STUB ILanguageExtender_GetParamDefValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_HasRetVal_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lMethodNum,
    /* [out][in] */ BOOL *pboolRetValue);


void __RPC_STUB ILanguageExtender_HasRetVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_CallAsProc_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lMethodNum,
    /* [in] */ SAFEARRAY * *paParams);


void __RPC_STUB ILanguageExtender_CallAsProc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILanguageExtender_CallAsFunc_Proxy( 
    ILanguageExtender * This,
    /* [in] */ long lMethodNum,
    /* [out][in] */ VARIANT *pvarRetValue,
    /* [in] */ SAFEARRAY * *paParams);


void __RPC_STUB ILanguageExtender_CallAsFunc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILanguageExtender_INTERFACE_DEFINED__ */


#ifndef __IStatusLine_INTERFACE_DEFINED__
#define __IStatusLine_INTERFACE_DEFINED__

/* interface IStatusLine */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStatusLine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ab634005-f13d-11d0-a459-004095e1daea")
    IStatusLine : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatusLine( 
            BSTR bstrStatusLine) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetStatusLine( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStatusLineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStatusLine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStatusLine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStatusLine * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatusLine )( 
            IStatusLine * This,
            BSTR bstrStatusLine);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetStatusLine )( 
            IStatusLine * This);
        
        END_INTERFACE
    } IStatusLineVtbl;

    interface IStatusLine
    {
        CONST_VTBL struct IStatusLineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStatusLine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStatusLine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStatusLine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStatusLine_SetStatusLine(This,bstrStatusLine)	\
    (This)->lpVtbl -> SetStatusLine(This,bstrStatusLine)

#define IStatusLine_ResetStatusLine(This)	\
    (This)->lpVtbl -> ResetStatusLine(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IStatusLine_SetStatusLine_Proxy( 
    IStatusLine * This,
    BSTR bstrStatusLine);


void __RPC_STUB IStatusLine_SetStatusLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IStatusLine_ResetStatusLine_Proxy( 
    IStatusLine * This);


void __RPC_STUB IStatusLine_ResetStatusLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStatusLine_INTERFACE_DEFINED__ */



#ifndef __AddInLib_LIBRARY_DEFINED__
#define __AddInLib_LIBRARY_DEFINED__

/* library AddInLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AddInLib;

EXTERN_C const CLSID CLSID_AddIn;

#ifdef __cplusplus

class DECLSPEC_UUID("04024C32-0E7B-11d1-A486-004095E1DAEA")
AddIn;
#endif

EXTERN_C const CLSID CLSID_AddInConnection;

#ifdef __cplusplus

class DECLSPEC_UUID("912B7392-250D-11d1-A4C8-004095E1DAEA")
AddInConnection;
#endif
#endif /* __AddInLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


