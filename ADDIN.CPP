// AddIn.cpp

#include "stdafx.h"
#include "AddIn.h"

struct CAddIn::paramdefs CAddIn::defFnNames[] = {
	{{L"AddToCash",L"ДобавитьВКэш"}, FALSE, 4},
	{{L"CmpNext",L"ДобавитьВПодбор"}, FALSE, 3},
	{{L"GetItemSet",L"ПолучитьИзПодбора"}, TRUE, 3},
	{{L"CmpWithCash",L"СравнитьСКэшем"}, FALSE, 3},
	{{L"StrMatch",L"Сравнить"}, TRUE, 2},
	{{L"OpenSet",L"ОткрытьПодбор"}, FALSE, 2},
	{{L"CreateCash",L"СоздатьКэш"}, TRUE, 1},
	{{L"ClearCash",L"ОчиститьКэш"}, FALSE, 1},
	{{L"DeleteCash",L"УдалитьКэш"}, FALSE, 1}
};

struct CAddIn::parampropdefs CAddIn::defPropNames[] = {
	{{L"Version",L"Версия"}, TRUE, FALSE}
};

/////////////////////////////////////////////////////////////////////////////
// CAddIn

CAddIn::CAddIn()
{
	EmptyString = ::SysAllocString(L"");
}

CAddIn::~CAddIn(){
	SysFreeString(EmptyString);
}

BOOL CAddIn::LoadProperties()
{  
	return TRUE;
}

void CAddIn::SaveProperties()
{
}

/* 
These two methods is convenient way to access function 
parameters from SAFEARRAY vector of variants
*/
VARIANT CAddIn::GetNParam(SAFEARRAY *pArray,long lIndex)
{
	ASSERT(pArray);
	ASSERT(pArray->fFeatures | FADF_VARIANT);

	VARIANT vt;
	HRESULT hRes = SafeArrayGetElement(pArray,&lIndex,&vt);
	ASSERT(hRes == S_OK);

	return vt;
}

void CAddIn::PutNParam(SAFEARRAY *pArray,long lIndex,VARIANT vt)
{
	ASSERT(pArray);
	ASSERT(pArray->fFeatures | FADF_VARIANT);

	HRESULT hRes = SafeArrayPutElement(pArray,&lIndex,&vt);
	ASSERT(hRes == S_OK);
}

/////////////////////////////////////////////////////////////////////////////
// IInitDone

STDMETHODIMP CAddIn::Init(IDispatch *pConnection)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	m_iErrorLog = NULL;
	pConnection->QueryInterface(IID_IErrorLog,(void **)&m_iErrorLog);

	/*
	CString csProfileName = "AddIn Profile Name";
	m_iProfile = NULL;
	pConnection->QueryInterface(IID_IPropertyProfile,(void **)&m_iProfile);
	m_iProfile->RegisterProfileAs(csProfileName.AllocSysString());
	*/

	m_iStatusLine = NULL;
	pConnection->QueryInterface(IID_IStatusLine,(void **)&m_iStatusLine);

	m_iAsyncEvent = NULL;
	pConnection->QueryInterface(IID_IAsyncEvent,(void **)&m_iAsyncEvent);

	// TODO: Add your implementation code here

	if (LoadProperties() == FALSE) return E_FAIL;

	return S_OK;
}

STDMETHODIMP CAddIn::Done()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here

		SaveProperties();

	if (m_iStatusLine) m_iStatusLine->Release();
	//if (m_iProfile) m_iProfile->Release();
	if (m_iErrorLog) m_iErrorLog->Release();
	if (m_iAsyncEvent) m_iAsyncEvent->Release();

	return S_OK;
}

STDMETHODIMP CAddIn::GetInfo(SAFEARRAY **pInfo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// Component should put supported component technology version 
		// in VARIANT at index 0     
	long lInd = 0;
	VARIANT varVersion;
	V_VT(&varVersion) = VT_I4;
	// This component supports 1.0 version
	V_I4(&varVersion) = 1000;
	SafeArrayPutElement(*pInfo,&lInd,&varVersion);

	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
// ILanguageExtender

STDMETHODIMP CAddIn::RegisterExtensionAs(BSTR *bstrExtensionName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// You may delete next lines and add your own implementation code here

		// Name of extension should be changed avoiding conflicts 
	CString csExtenderName = "StrMatchExtension";
	*bstrExtensionName = csExtenderName.AllocSysString();

	return NULL;
}

STDMETHODIMP CAddIn::GetNProps(long *plProps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		*plProps = LastProp;

	return S_OK;
}

STDMETHODIMP CAddIn::FindProp(BSTR bstrPropName,long *plPropNum)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	*plPropNum = -1;

	for (int i = 0; i < LastProp; i++)
	{
		if (!_wcsicmp(bstrPropName,defPropNames[i].Names[0]) || !_wcsicmp(bstrPropName,defPropNames[i].Names[1])){
			*plPropNum = i;

			return S_OK;
		}
	}
	return S_FALSE;
}

STDMETHODIMP CAddIn::GetPropName(long lPropNum, long lPropAlias, BSTR *pbstrPropName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	if ((lPropNum >= 0) && (lPropNum < LastProp)){
		*pbstrPropName = ::SysAllocString((BSTR)defPropNames[lPropNum].Names[lPropAlias]);

		return S_OK;
	}

	*pbstrPropName = ::SysAllocString(L"");
	return S_FALSE;
}

STDMETHODIMP CAddIn::GetPropVal(long lPropNum,VARIANT *pvarPropVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	VariantInit(pvarPropVal);

	switch (lPropNum) {
		case propVer:
			V_VT(pvarPropVal) = VT_BSTR;
			V_BSTR(pvarPropVal) = ::SysAllocString(L"2.1.1");
			break;
		default:
			return S_FALSE;
	};
	return S_OK;
}

STDMETHODIMP CAddIn::SetPropVal(long lPropNum,VARIANT *pvarPropVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	switch (lPropNum) {

		default:
			return S_FALSE;
	};
	return S_OK;
}

STDMETHODIMP CAddIn::IsPropReadable(long lPropNum,BOOL *pboolPropRead)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		if ((lPropNum >= 0) && (lPropNum < LastProp)){
			*pboolPropRead = defPropNames[lPropNum].IsReadable;
			return S_OK;
		}

		*pboolPropRead = FALSE;
		return S_FALSE;
}

STDMETHODIMP CAddIn::IsPropWritable(long lPropNum, BOOL *pboolPropWrite)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		if ((lPropNum >= 0) && (lPropNum < LastProp)){
			*pboolPropWrite = defPropNames[lPropNum].IsWritable;
			return S_OK;
		}

		*pboolPropWrite = FALSE;
		return S_FALSE;
}

STDMETHODIMP CAddIn::GetNMethods(long *plMethods)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	*plMethods = LastMethod;

	return S_OK;
}

STDMETHODIMP CAddIn::FindMethod(BSTR bstrMethodName,long *plMethodNum)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	for (int i = 0; i < LastMethod; i++)
	{
		if (!_wcsicmp(bstrMethodName,defFnNames[i].Names[0]) || !_wcsicmp(bstrMethodName,defFnNames[i].Names[1])){
			*plMethodNum = i;

			return S_OK;
		}
	}

	*plMethodNum = -1;
	return S_FALSE;
}

STDMETHODIMP CAddIn::GetMethodName(long lMethodNum, long lMethodAlias, BSTR *pbstrMethodName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	if ((lMethodNum >= 0) && (lMethodNum < LastMethod)){
		*pbstrMethodName = ::SysAllocString((BSTR)defFnNames[lMethodNum].Names[lMethodAlias]);

		return S_OK;
	}

	*pbstrMethodName = ::SysAllocString(L"");
	return S_FALSE;
}

STDMETHODIMP CAddIn::GetNParams(long lMethodNum, long *plParams)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		if ((lMethodNum >= 0) && (lMethodNum < LastMethod)){
			*plParams = defFnNames[lMethodNum].NumberOfParams;
			return S_OK;
		}

		*plParams = 0;
		return S_FALSE;
}

STDMETHODIMP CAddIn::GetParamDefValue(long lMethodNum, long lParamNum, VARIANT *pvarParamDefValue)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here

	VariantInit(pvarParamDefValue);
	
	int RetValue = -1;
	switch(lMethodNum){ 
		case methCreateCache:
			RetValue = GetID();
	}
	
	if(RetValue >= 0){
		V_VT(pvarParamDefValue) = VT_I4;
		V_I4(pvarParamDefValue) = RetValue;
		return S_OK;
	}

	return S_FALSE;

	//VariantInit(pvarParamDefValue);
	//switch(lMethodNum)
	//{ 

	//	/* 
	//	Differentiate cases here:
	//	case Method1: ...
	//	case Method2: ...
	//	...
	//	*/
	//default:
	//	return S_FALSE;
	//}

	//return S_OK;
}

STDMETHODIMP CAddIn::HasRetVal(long lMethodNum, BOOL *pboolRetValue)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		if ((lMethodNum >= 0) && (lMethodNum < LastMethod)){
			*pboolRetValue = defFnNames[lMethodNum].HasReturnValue;
			return S_OK;
		}

		*pboolRetValue = FALSE;
		return S_FALSE;
}

STDMETHODIMP CAddIn::CallAsProc(long lMethodNum, SAFEARRAY **paParams)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	CString p1, p2;

		switch(lMethodNum)
	{ 
		case methAddToCache:
			p1 = GetBstr(&GetNParam(*paParams, 1));
			p2 = GetBstr(&GetNParam(*paParams, 3));
			AddToCash(GetInt(&GetNParam(*paParams, 0)), p1.GetBuffer(), GetInt(&GetNParam(*paParams, 2)), p2.GetBuffer());
			p1.ReleaseBuffer();
			p2.ReleaseBuffer();
			break;

		case methCmpNext:
			p1 = GetBstr(&GetNParam(*paParams, 0));
			p2 = GetBstr(&GetNParam(*paParams, 2));
			CmpNext(p1.GetBuffer(), GetInt(&GetNParam(*paParams, 1)), p2.GetBuffer());
			p1.ReleaseBuffer();
			p2.ReleaseBuffer();
			break;
		
		case methOpenSet:
			p1 = GetBstr(&GetNParam(*paParams, 0));
			OpenSet(p1.GetBuffer(), GetInt(&GetNParam(*paParams, 1)));
			p1.ReleaseBuffer();
			break;
		
		case metchCmpWithCache:
			p1 = GetBstr(&GetNParam(*paParams, 1));
			CmpWithCash(GetInt(&GetNParam(*paParams, 0)), p1.GetBuffer(), GetInt(&GetNParam(*paParams, 2)));
			p1.ReleaseBuffer();
			break;

		case methClearCache:
			ClearCash(GetInt(&GetNParam(*paParams, 0)));
			break;

		case metchDeleteCache:
			DeleteCash(GetInt(&GetNParam(*paParams, 0)));
			break;

		default:
			return S_FALSE;
	}

	return S_OK;
}

STDMETHODIMP CAddIn::CallAsFunc(long lMethodNum, VARIANT *pvarRetValue, SAFEARRAY **paParams)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
	VariantInit(pvarRetValue);

	CString p1, p2;
	long ind;
	UINT IDCash;
	char buf[64];
	
	VARIANT vt;
	VariantInit(&vt);
	
		switch(lMethodNum)
	{ 
		case methGetItem:
			if((&GetNParam(*paParams, 1))->vt == VT_BSTR)
				::SysFreeString(V_BSTR(&GetNParam(*paParams, 1)));
			
			V_VT(pvarRetValue) = VT_I4;
			V_I4(pvarRetValue) = GetCmpItem(GetInt(&GetNParam(*paParams, 0)), buf, &ind);
			
			V_VT(&vt) = VT_BSTR;
			p1 = buf;
			V_BSTR(&vt) = p1.AllocSysString();
			PutNParam(*paParams, 1, vt);
			
			V_VT(&vt) = VT_I4;
			V_I4(&vt) = ind;
			PutNParam(*paParams, 2, vt);
			break;

		case methStrMatch:
			p1 = GetBstr(&GetNParam(*paParams, 0));
			p2 = GetBstr(&GetNParam(*paParams, 1));
			V_VT(pvarRetValue) = VT_I4;
			V_I4(pvarRetValue) = StrMatch(p1.GetBuffer(), p2.GetBuffer());
			p1.ReleaseBuffer();
			p2.ReleaseBuffer();
			break;
		
		case methCreateCache:
			IDCash = GetInt(&GetNParam(*paParams, 0));
			CreateCash(IDCash);
			V_VT(pvarRetValue) = VT_I4;
			V_I4(pvarRetValue) = IDCash;
			break;

		case methSaveCache:
			p1 = GetBstr(&GetNParam(*paParams, 1));
			V_VT(pvarRetValue) = VT_I4;
			V_I4(pvarRetValue) = SaveCache(GetInt(&GetNParam(*paParams, 0)), p1.GetBuffer());
			p1.ReleaseBuffer();
			break;

		case methLoadCache:
			p1 = GetBstr(&GetNParam(*paParams, 1));
			V_VT(pvarRetValue) = VT_I4;
			V_I4(pvarRetValue) = LoadCache(GetInt(&GetNParam(*paParams, 0)), p1.GetBuffer());
			p1.ReleaseBuffer();
			break;

		default:
			return S_FALSE;

	}

	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
// IPropertyPage
/*
STDMETHODIMP CAddIn::SetPageSite(IPropertyPageSite *pPageSite)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::SetPageSite(pPageSite);
}

STDMETHODIMP CAddIn::Activate(HWND hWndParent,LPCRECT prc,BOOL bModal)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::Activate(hWndParent,prc,bModal);
}

STDMETHODIMP CAddIn::Deactivate()
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::Deactivate();
}

STDMETHODIMP CAddIn::GetPageInfo(PROPPAGEINFO *pPageInfo)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::GetPageInfo(pPageInfo);
}

STDMETHODIMP CAddIn::SetObjects(ULONG cObjects,IUnknown **ppUnk)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::SetObjects(cObjects,ppUnk);
}

STDMETHODIMP CAddIn::Show(UINT nCmdShow)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::Show(nCmdShow);
}

STDMETHODIMP CAddIn::Move(LPCRECT prc)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::Move(prc);
}

STDMETHODIMP CAddIn::IsPageDirty()
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::IsPageDirty();
}

STDMETHODIMP CAddIn::Apply()
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::Apply();
}

STDMETHODIMP CAddIn::Help(LPCOLESTR pszHelpDir)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::Help(pszHelpDir);
}

STDMETHODIMP CAddIn::TranslateAccelerator(LPMSG pMsg)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here

return IPropertyPageImpl<CAddIn>::TranslateAccelerator(pMsg);
}


LRESULT CAddIn::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
// TODO: Add your implementation code here

SetDirty(FALSE);
m_pPageSite->OnStatusChange(0);
bHandled = FALSE;

return 0; 
}

LRESULT CAddIn::OnCommand(WORD wNotifyCode, WORD nID, HWND hWndCtl, BOOL& bHandled)
{
// TODO: Add your implementation code here

SetDirty(TRUE);
bHandled = FALSE;

return 0;
}
*/