// StrMatch.cpp: implementation of the CStrMatch class.
//
//////////////////////////////////////////////////////////////////////

#include "..\stdafx.h"
#include "StrMatch.h"

#include <string.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ListNode::~ListNode(){
	if(str) delete str;
	if(name) delete name;
}
//**************************************************************************

CStrMatch::CStrMatch()
{
	InitReplaceStrings();

	TranslitFild = new char[65536];
	memset(TranslitFild, char(0), 65536);

	buf	= new char[1024];

	for(USHORT i = 0, *tmp = (USHORT*)pair; i < sizeof(__pas_); i++, tmp++)
		TranslitFild[*tmp] = *(pas+i);

	LastStr1 = new char[1024];
	LastStr2 = new char[1024];
	

	StringSet = (StringSetNode*)0;
	StringSetSize = 0;
	
	MinStringSetNode = StringSet;
	MinCmpIndex = 0;

	head = 0;
	LastUsedCash = 0;

	NumWeight = 4;
	
	IDCount = 0;
}

//**************************************************************************

CStrMatch::~CStrMatch()
{
	delete[] TranslitFild;
	delete[] buf;
	delete[] LastStr1;
	delete[] LastStr2;

	while(head)
		DeleteCash(head->id);

	CloseSet();
}

//**************************************************************************

void CStrMatch::InitReplaceStrings(){
	strcpy(alf, __alf_);
	strcpy(alf1, __alf1_);
	strcpy(alf2, __alf2_);
	strcpy(cns1, __cns1_);
	strcpy(cns2, __cns2_);
	strcpy(cns3, __cns3_);
	strcpy(ch, __ch_);
	strcpy(ct, __ct_);
	strcpy(pair, __pairs_);
	strcpy(pas, __pas_);
	strcpy(trl, __transl_);
	strcpy(trr, __transr_);
}

inline ListOfCash* CStrMatch::findcash(UINT id){
	if(LastUsedCash && LastUsedCash->id == id) return LastUsedCash;
	//ListOfCash* akt = head;
	for(ListOfCash* akt = head; akt; akt = akt->next){
		if(id < akt->id) continue;
		if(akt->id == id) return (LastUsedCash = akt);
		break;
	}
	//while(akt){
	//	if(akt->id == id) return (LastUsedCash = akt);
	//	akt = akt->next;
	//}
	return 0;
}
//**************************************************************************

void CStrMatch::CreateCash(UINT id){
	if(!head){
		LastUsedCash = head = new ListOfCash;
		head->next = 0;
	}else{
		if(findcash(id)) return;
		for(ListOfCash* akt = head, *nxt; nxt = akt->next; akt = nxt){
			if(id > nxt->id) break;
		}
		LastUsedCash = new ListOfCash;
		if(id > akt->id) //вставл€ем первым
			LastUsedCash->next = akt;
		else{
			LastUsedCash->next = akt->next;
			akt->next = LastUsedCash;
		}
	}
	LastUsedCash->id = id;
	LastUsedCash->first = 0;
	LastUsedCash->last = 0;
}

//**************************************************************************

void CStrMatch::ClearCash(UINT id){
	ListOfCash* del = findcash(id);
	if(!del) return;
	ListNode* tmp = del->first, *akt;
	while(akt = tmp){
		tmp = akt->next;
		delete akt;
	}
	del->first = 0;
	del->last = 0;

}

//**************************************************************************

void CStrMatch::DeleteCash(UINT id){
	if(!findcash(id)) return;
	ClearCash(id);
	ListOfCash* akt = head, *tmp = head;
	while(akt->id != id)
		akt = (tmp = akt) -> next;
	tmp->next = akt->next;
	if(akt == head) head = akt->next;
	delete akt;
	LastUsedCash = head;
}

//**************************************************************************

void CStrMatch::AddToCash(UINT id, char *str, UINT hash, char *name){
	ListOfCash* akt;
	ListNode* node;
	int _len;
	if(!(akt = findcash(id))) return;
	if(!(node = akt->last)){
		akt->first = new ListNode;
		node = (akt->last = akt->first);
	}
	else{
		node = (node->next = new ListNode);
		akt->last = node;
	}
	node->hash = hash;
	strncpy(LastStr1, str, 1023);
	LastStr1[1023] = char(0);
	
	node->str = new char[_len = PrepareString(LastStr1)+1];
	strncpy(node->str, LastStr1, _len);	
	node->name = new char[64];
	strncpy(node->name, name, 63);
	node->name[63] = char(0);
  
}

//**************************************************************************

void CStrMatch::CmpWithCash(UINT id, char *str, int size){
	ListOfCash* akt;
	ListNode* node;

	if(!(akt = findcash(id))) return;
	
	OpenSet(str, size);
	
	if(!(node = akt->first)) return;
	do{
		CmpNext(node->str, node->hash, node->name, true);
	}while(node = node->next);
}

//**************************************************************************

void CStrMatch::CloseSet(void){
	if(!StringSetSize) return;

	delete[] StringSet;

	StringSetSize = 0;
}

//**************************************************************************

void CStrMatch::OpenSet(char *str, int size){
	if(size < 1) return;
	
	CloseSet();
	
	strncpy(LastStr1, str, 1023);
	LastStr1[1023] = char(0);
	PrepareString(LastStr1);

	StringSetSize = size;
	StringSet = new StringSetNode[StringSetSize];

	StringSetNode *worker = StringSet;
	for(UINT i = 0; i < StringSetSize; i++, worker++){
		worker->Hash = 0;
		worker->name[0] = char(0);
		worker->CmpIndex = 0;
	}
	
	MinStringSetNode = StringSet;
	MinCmpIndex = -1;
	SSTableNotFull = size;
	IsSorted = false;
}

//**************************************************************************

UINT CStrMatch::GetCmpItem(UINT num, char *name, long *Ind){
	UINT size, i, j;
	*name = char(0);
	*Ind = 0;
	if(!StringSetSize || num > (size = StringSetSize - SSTableNotFull) || !num)
		return 0;
	
	if(IsSorted){
		strncpy(name, StringSet[num-1].name, 63);
		name[63] = 0;
		*Ind = StringSet[num-1].CmpIndex;
		return StringSet[num-1].Hash;
	}
	else{
		StringSetNode *BeginList = StringSet;
		
		if(SSTableNotFull){
			if(SSTableNotFull == StringSetSize)	return 0;
			BeginList += SSTableNotFull;
		}
		else IsSorted = true;
		StringSetNode *tmpI, *tmpJ;
		BYTE buf[sizeof(StringSetNode)];
		for(i = 1, tmpI = BeginList+1; i < size; i++, tmpI++)
			for(j = 0, tmpJ = BeginList; j < i; j++, tmpJ++)
				if(tmpI->CmpIndex > tmpJ->CmpIndex){
					memcpy(buf, tmpI, sizeof(StringSetNode));
					memcpy(tmpI, tmpJ, sizeof(StringSetNode));
					memcpy(tmpJ, buf, sizeof(StringSetNode));
				}
		strncpy(name, BeginList[num-1].name, 63);
		name[63] = 0;
		*Ind = StringSet[num-1].CmpIndex;
		return BeginList[num-1].Hash;
	}
	return 0;
}

//**************************************************************************

void CStrMatch::CmpNext(char *str, UINT hash, char *name, bool fromCash)
{
	if(!StringSetSize) return;
	IsSorted = false;
	UINT ind = StrMatch((char*)0, str, fromCash);
	if(SSTableNotFull){
		SSTableNotFull--;
		StringSet[SSTableNotFull].Hash = hash;
		strncpy(StringSet[SSTableNotFull].name, name, 63);
		StringSet[SSTableNotFull].name[63] = char(0);
		StringSet[SSTableNotFull].CmpIndex = ind;
		if(ind < MinCmpIndex){
			MinCmpIndex = ind;
			MinStringSetNode = StringSet + SSTableNotFull;
		}
	}else
		if(ind > MinCmpIndex){
			MinStringSetNode->Hash = hash;
			strncpy(MinStringSetNode->name, name, 63);
			MinStringSetNode->name[63] = char(0);
			MinStringSetNode->CmpIndex = ind;
			MinCmpIndex = ind;
			
			StringSetNode *worker = StringSet;
			for(UINT i = 0; i < StringSetSize; i++, worker++)
				if(worker->CmpIndex < MinCmpIndex){
					MinCmpIndex = worker->CmpIndex;
					MinStringSetNode = worker;
				}
		}
}


//**************************************************************************



int CStrMatch::StrMatch(char *str1, char *str2, bool fromCash)
{
	int _small, _large;
	int len1, len2, charlen1, charlen2;
	char *smallstr,*largstr;
	register char *ss, *sss;
	int score = 0;
	
	if(str1){
		strncpy(LastStr1, str1, 1023);
		LastStr1[1023] = char(0);

		len1 = PrepareString(LastStr1);
	}else
		len1 = strlen(LastStr1);

	strncpy(LastStr2, str2, 1023);
	LastStr2[1023] = char(0);
	
	if(!fromCash)
		len2 = PrepareString(LastStr2);
	else
		len2 = strlen(LastStr2);

	charlen1 = strcspn(LastStr1, alf2);
	charlen2 = strcspn(LastStr2, alf2);

	// ѕровер€ем отдельно строковую часть и числовую.
	//—начала строковую

	if(charlen1 < charlen2) {
		smallstr = LastStr1;
		_small = charlen1;
		largstr = LastStr2;
		_large = charlen2;
	}
	else {
		smallstr = LastStr2;
		_small = charlen2;
		largstr = LastStr1;
		_large = charlen1;
	}
	
	int _from = __MinChars_, _to = _small;
	if(_to > __MaxChars_ )
/*		if(_to > __MaxChars_ * 3)
			_to / 3;
		else */
			_to = __MaxChars_;

	int k, i, tmp;
	char save_c, save_cl;
	
	save_cl = largstr[_large];
	largstr[_large] = char(0);
	for(k = _to; k >= _from; k--)
		for(i = 0, tmp = _small - k, ss = smallstr; i++ <= tmp; ss++){
			sss = ss + k;
			save_c = *sss;
			*sss = char(0);
			if(strstr(largstr, ss)) //существуют совпадающие подстроки
				score += k;
			*sss = save_c;
		}
	largstr[_large] = save_cl;

	/*
	//старый вариант:
	for(int k = _to; k >= _from; k--)
		for(i = 0, tmp1 = _large - k, ls = largstr; i <= tmp1; i++, ls++)
			for(j = 0, tmp2 = _small - k, ss = smallstr; j <= tmp2; j++, ss++)
				if(!strncmp(ls, ss, k)){
					score += k;
					break;
				}

	 интересна апроксимаци€:
	 Score{k} = { a=k-1; a*(1/6*a^2+a+5/6) }
	 дает сумму вклада очков дл€ подстроки длиной k
	 (сходу, что это всегда цела€ величина доказать не смог)
	 ƒл€ этой же величины получил рекуррентную формулу:
	 Score{k} = Score{a} + ((2+k)/2*(k-1))
	 где последнее слагаемое это сумма членов арифметич. прогрессии от 2 до k
	 (тут из определени€ €сно, что будут получатьс€ только целые значени€)
	  ак все грамотно всунуть думать лень, если не будет хватать скорости - вернусь
	*/

	//«атем провер€ем числовую.
	
	if(NumWeight == 0)
		return score;

	int lennum1 = len1 - charlen1;
	int lennum2 = len2 - charlen2;
	
	if(lennum1 < lennum2) {
		smallstr = LastStr1 + charlen1;
		_small = lennum1;
		largstr = LastStr2 + charlen2;
		_large = lennum2;
	}
	else {
		smallstr = LastStr2+charlen2;
		_small = lennum2;
		largstr = LastStr1+charlen1;
		_large = lennum1;
	}

	if(_small){
		if(_small == 1 && _large == 1 && *smallstr == *largstr)
			return score + 5;
		
		_from = 2, _to = _small;
		if(_to > 3 ) _to = 3;
		
		for(k = _to; k >= _from; k--)
			for(i = 0, tmp = _small - k, ss = smallstr; i++ <= tmp; ss++){
				sss = ss + k;
				save_c = *sss;
				*sss = char(0);
				if(strstr(largstr, ss)) //существуют совпадающие подстроки
					score += (k * NumWeight); //¬клад чисел идет с отдельным весом
				*sss = save_c;
			}
	}

	return score;
}


//**************************************************************************

int CStrMatch::PrepareString(char* str)
{
	char *pnS, *pS, *tmp;
	unsigned char c, old_c;
	Translit(str);
	old_c = ' ';
	int dc = 'а' - 'ј', NumCount = 0;
	for(pnS = pS = str; *pS; pS++){
		c = *pS;
		if(c > (unsigned char)'я' || c == 'Є') //переводим в верхний регистр
			if(c == 'Є') c = '®';
			else c -= dc;
		if(strchr(alf, c)){ //оставл€ем только перечисленные в alt
			//гласные после '…' оставл€ем без изменений и записываем вместо '…'
			if(old_c == '…' && strchr(alf1, c))
				*(--pnS) = c;
			else 
				if(tmp = strchr(ch, c)) *pnS = *(ct + (tmp - ch)); //замена гласных
				else *pnS = c;
			old_c = *pnS;
			pnS++;
		} else {
			old_c = ' ';
			if(strchr(alf2, c))
				buf[NumCount++] = c; //„исла переписываем в конец
		}
	}
	*pnS = char(0);
	
	old_c = ' ';
	for(pnS = pS = str; *pS; pS++){
		c = *pS;
		if(old_c == c) continue;
		if(tmp = strchr(cns1, old_c))
			if(strchr(cns3, c)){
				old_c = *(cns2 + (tmp - cns1));
				*(pnS-1) = old_c; //замена на глухую согласную
			}
		if(old_c == c) continue;
		old_c = c;
		*pnS = c;
		pnS++;
	}
	if(NumCount){
		buf[NumCount] = char(0);
		strcpy(pnS, buf);
		pnS += NumCount;
	}
	*pnS = char(0);

	return pnS - str;
}

//**************************************************************************

int CStrMatch::Translit(char* str)
{
	char *pnS, *pS, tmp1, *tmp2;
	_strupr(str);
	for(pnS = pS = str; *pS; pS++){
		if(tmp1 = *(TranslitFild + *(USHORT*)pS)){ //транслит некоторых слогов
			*(pnS++) = tmp1;
			pS++;
			continue;
		}
		if(tmp2 = strchr(trl, *pS)) *pnS = *(trr + (tmp2 - trl)); //транслит букв
		else *pnS = *pS; //просто копируем, это и так видимо русска€ буква
		pnS++;
	}
	*pnS = char(0);
	
	return pnS-str;
}

int CStrMatch::SaveCache(UINT id, char *fname){
	return 1;
}

int CStrMatch::LoadCache(UINT id, char *fname){
	//ReadFile
	return 1;
}