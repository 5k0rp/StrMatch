// StrMatch.h: interface for the CStrMatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRMATCH_H__FA0EEFF0_2CE6_46E5_8DFD_89B749032ACA__INCLUDED_)
#define AFX_STRMATCH_H__FA0EEFF0_2CE6_46E5_8DFD_89B749032ACA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define __alf_ "ќ≈ј»”Ёёяѕ—“– ЋћЌЅ¬√ƒ∆«…‘’÷„Ўў®џ" //алфавит кроме исключаемых букв
#define __alf1_ "ј≈®»ќ”џЁёяя" //все гласные
#define __alf2_ "01234567899" //все, что переноситс€ в конец строки 
#define __cns1_ "Ѕ«ƒ¬√√√" //звонкие согласные
#define __cns2_ "ѕ—“‘   " //глухие согласные
#define __cns3_ "ѕ—“ Ѕ¬√ƒ∆«‘’÷„Ўўўўў" //согласные, перед которыми звонкие оглушаютс€
#define __ch_ "®яё≈џќќ" //образец и ...
#define __ct_ "ќј”Ё»јј" //замена гласных

#define __pairs_ "SHCHORAROOTHERCKPHIREEEAWHGHYAYUYE" //транслит пар	 
#define	__pas_ "Ў„ќј”¬® ‘®»»¬’яё≈" //на что мен€ем
#define	__transl_ "ABCDEFGHIJGKLMNOPQRSTUVWXYZ" //не совсем честный транслит, ориентирован на то как слышитс€
#define	__transr_ "јЅ ƒ≈‘√’»…√ ЋћЌќѕ –—“”¬¬ »«"

#define	__MinChars_ 2
#define	__MaxChars_ 5

struct StringSetNode{
	UINT CmpIndex;
	UINT Hash;
	char name[64];
};

struct ListNode{
	ListNode(): next(0), str(0), name(0){}
	virtual ~ListNode();
	ListNode* next;
	UINT hash;
	char* str;
	char* name;
};

struct ListOfCash{
	ListOfCash* next;
	UINT id;
	ListNode* first;
	ListNode* last;
};

class CStrMatch
{
	char alf[sizeof(__alf_)];
	char alf1[sizeof(__alf1_)];
	char alf2[sizeof(__alf2_)];
	char cns1[sizeof(__cns1_)];
	char cns2[sizeof(__cns2_)];
	char cns3[sizeof(__cns3_)];
	char ch[sizeof(__ch_)];
	char ct[sizeof(__ct_)];

	char pair[sizeof(__pairs_)];
	char pas[sizeof(__pas_)];
	char trl[sizeof(__transl_)];
	char trr[sizeof(__transr_)];

	UINT MinCmpIndex;
	StringSetNode* MinStringSetNode;
	UINT SSTableNotFull;
	bool IsSorted;

	char* TranslitFild;
	char* buf;

	UINT StringSetSize;
	StringSetNode* StringSet;

	ListOfCash* head;
	ListOfCash* LastUsedCash;
	
	void InitReplaceStrings();
	
	inline ListOfCash* findcash(UINT id);

	UINT IDCount;

public:
	CStrMatch();
	virtual ~CStrMatch();

	int StrMatch(char *str1, char *str2, bool fromCash = false);

	void OpenSet(char *str, int size);
	void CmpNext(char *str, UINT hash, char *name, bool fromCash = false);
	
	UINT GetID(void){
		while(findcash(++IDCount));
		return IDCount;
	}
	
	void CreateCash(UINT id);
	void ClearCash(UINT id);
	void DeleteCash(UINT id);
	void AddToCash(UINT id, char *str, UINT hash, char *name);
	void CmpWithCash(UINT id, char *str, int size);
	
	UINT GetCmpItem(UINT num, char *name, long *Ind);
	
	void CloseSet(void);

	UINT NumWeight;

	int SaveCache(UINT id, char *fname);
	int LoadCache(UINT id, char *fname);

protected:

	char* LastStr1;
	char* LastStr2;

	int PrepareString(char* str);
	int Translit(char* str);
	
};

#endif // !defined(AFX_STRMATCH_H__FA0EEFF0_2CE6_46E5_8DFD_89B749032ACA__INCLUDED_)
