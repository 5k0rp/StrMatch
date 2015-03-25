

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Tue Sep 02 14:28:29 2008
 */
/* Compiler settings for AddIn.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IInitDone,0xAB634001,0xF13D,0x11d0,0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IPropertyProfile,0xAB634002,0xF13D,0x11d0,0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IAsyncEvent,0xab634004,0xf13d,0x11d0,0xa4,0x59,0x00,0x40,0x95,0xe1,0xda,0xea);


MIDL_DEFINE_GUID(IID, IID_ILanguageExtender,0xAB634003,0xF13D,0x11d0,0xA4,0x59,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(IID, IID_IStatusLine,0xab634005,0xf13d,0x11d0,0xa4,0x59,0x00,0x40,0x95,0xe1,0xda,0xea);


MIDL_DEFINE_GUID(IID, LIBID_AddInLib,0x4F0D4571,0x0E7B,0x11d1,0xA4,0x86,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(CLSID, CLSID_AddIn,0x04024C32,0x0E7B,0x11d1,0xA4,0x86,0x00,0x40,0x95,0xE1,0xDA,0xEA);


MIDL_DEFINE_GUID(CLSID, CLSID_AddInConnection,0x912B7392,0x250D,0x11d1,0xA4,0xC8,0x00,0x40,0x95,0xE1,0xDA,0xEA);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



