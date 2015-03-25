// AddIn.h: Definition of the CAddIn class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDIN_H__FC223DE1_F108_11D0_A459_004095E1DAEA__INCLUDED_)
#define AFX_ADDIN_H__FC223DE1_F108_11D0_A459_004095E1DAEA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "resource.h"       // main symbols
#include "AddInTlb.h"
#include "atlctl.h"

#include "include\StrMatch.h"

/*
  These are error codes that should be used in AddError
*/
enum AddInErrors {
                  ADDIN_E_NONE = 1000,
                  ADDIN_E_ORDINARY = 1001,
                  ADDIN_E_ATTENTION = 1002,
                  ADDIN_E_IMPORTANT = 1003,
                  ADDIN_E_VERY_IMPORTANT = 1004,
                  ADDIN_E_INFO = 1005,
                  ADDIN_E_FAIL = 1006,
                  ADDIN_E_MSGBOX_ATTENTION = 1007,
                  ADDIN_E_MSGBOX_INFO = 1008,
                  ADDIN_E_MSGBOX_FAIL = 1009
                 };

class CAddIn;

/////////////////////////////////////////////////////////////////////////////
// CAddIn

class CAddIn : 
	public IInitDone,
	public ILanguageExtender,
    public CComObjectRoot,
	public CComCoClass<CAddIn,&CLSID_AddIn>,
	public CStrMatch
	//public IPropertyPageImpl<CAddIn>,
	//public CDialogImpl<CAddIn>
{
	enum {
		methAddToCache,
		methCmpNext,
		methGetItem,
		metchCmpWithCache,
		methStrMatch,
		methOpenSet,
		methCreateCache,
		methClearCache,
		metchDeleteCache,
		methSaveCache,
		methLoadCache,
		LastMethod
	};

	static struct paramdefs {
		BSTR Names[2];
		BOOL HasReturnValue;
		BOOL NumberOfParams;
	}  defFnNames[];

	enum {
		propVer,
		LastProp
	};

	static struct parampropdefs {
		BSTR Names[2];
		BOOL IsReadable;
		BOOL IsWritable;
	}  defPropNames[];

	double GetDouble(VARIANT* vt){
		switch(vt->vt){
            case VT_R8:
				return V_R8(vt);
			case VT_I4:
				return (double)V_I4(vt);
		}
		return 0.;
	}

	int GetInt(VARIANT* vt){
		switch(vt->vt){
			case VT_I4:
				return V_I4(vt);
			case VT_R8:
				return (int)V_R8(vt);
		}
		return 0;
	}

	BSTR EmptyString;
	BSTR GetBstr(VARIANT* vt){
		if(vt->vt == VT_BSTR)
				return V_BSTR(vt);

		return EmptyString;
	}

public:
	CAddIn();
	~CAddIn();

// Attributes
    IErrorLog *m_iErrorLog;
    //IPropertyProfile *m_iProfile;
    IStatusLine *m_iStatusLine;
    IAsyncEvent *m_iAsyncEvent;

// Methods
      /* Add your method definitions here */
    BOOL LoadProperties();
    void SaveProperties();
      // This method is very useful in ILanguageExtender implementation
    //CString TermString(UINT uiResID,long nAlias);
      // These two methods is convenient way to access function 
      // parameters from SAFEARRAY vector of variants
    VARIANT GetNParam(SAFEARRAY *pArray,long lIndex);
    void PutNParam(SAFEARRAY *pArray,long lIndex, VARIANT vt);

// Interfaces

BEGIN_COM_MAP(CAddIn)
	COM_INTERFACE_ENTRY(IInitDone)
	COM_INTERFACE_ENTRY(ILanguageExtender)
	//COM_INTERFACE_ENTRY_IMPL(IPropertyPage)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CAddIn) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

/*
enum {IDD = IDD_ADDIN_PROP_PAGE};

LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
LRESULT OnCommand(WORD wNotify, WORD wID, HWND hWnd, BOOL& bHandled);

BEGIN_MSG_MAP(CAddIn)
    MESSAGE_HANDLER(WM_INITDIALOG,OnInitDialog)
      // Sample WM_COMMAND handler
    COMMAND_CODE_HANDLER(BN_CLICKED,OnCommand)
    CHAIN_MSG_MAP(IPropertyPageImpl<CAddIn>)
END_MSG_MAP()
*/
DECLARE_REGISTRY_RESOURCEID(IDR_AddIn)

// IInitDone
public:
	STDMETHOD(Init)(IDispatch *pConnection);
	STDMETHOD(Done)();
    STDMETHOD(GetInfo)(SAFEARRAY **pInfo);

// ILanguageExtender
public:

	STDMETHOD(RegisterExtensionAs)(BSTR *bstrExtensionName);

	STDMETHOD(GetNProps)(long *plProps);
	STDMETHOD(FindProp)(BSTR bstrPropName,long *plPropNum);
	STDMETHOD(GetPropName)(long lPropNum,long lPropAlias,BSTR *pbstrPropName);
	STDMETHOD(GetPropVal)(long lPropNum,VARIANT *pvarPropVal);
	STDMETHOD(SetPropVal)(long lPropNum,VARIANT *pvarPropVal);
	STDMETHOD(IsPropReadable)(long lPropNum,BOOL *pboolPropRead);
	STDMETHOD(IsPropWritable)(long lPropNum,BOOL *pboolPropWrite);

	STDMETHOD(GetNMethods)(long *plMethods);
	STDMETHOD(FindMethod)(BSTR bstrMethodName,long *plMethodNum);
	STDMETHOD(GetMethodName)(long lMethodNum,long lMethodAlias,BSTR *pbstrMethodName);
	STDMETHOD(GetNParams)(long lMethodNum,long *plParams);
	STDMETHOD(GetParamDefValue)(long lMethodNum,long lParamNum,VARIANT *pvarParamDefValue);
	STDMETHOD(HasRetVal)(long lMethodNum,BOOL *pboolRetValue);
	STDMETHOD(CallAsProc)(long lMethodNum,SAFEARRAY **paParams);
	STDMETHOD(CallAsFunc)(long lMethodNum,VARIANT *pvarRetValue,SAFEARRAY **paParams);

// IPropertyPage
/*
public:
	STDMETHOD(SetPageSite)(IPropertyPageSite *pPageSite);
	STDMETHOD(Activate)(HWND hWndParent,LPCRECT prc,BOOL bModal);
	STDMETHOD(Deactivate)();
	STDMETHOD(GetPageInfo)(PROPPAGEINFO *pPageInfo);
	STDMETHOD(SetObjects)(ULONG cObjects,IUnknown **ppUnk);
	STDMETHOD(Show)(UINT nCmdShow);
	STDMETHOD(Move)(LPCRECT prc);
	STDMETHOD(IsPageDirty)();
	STDMETHOD(Apply)();
	STDMETHOD(Help)(LPCOLESTR pszHelpDir);
	STDMETHOD(TranslateAccelerator)(LPMSG pMsg);
*/
};

#endif // !defined(AFX_ADDIN_H__FC223DE1_F108_11D0_A459_004095E1DAEA__INCLUDED_)
