#ifndef _BDSL_BASE_H_
#define _BDSL_BASE_H_ 0x1
#include <stdlib.h>
#include <string.h>
#ifndef BOOL
typedef char BOOL;
#define TRUE 1
#define FALSE 0
#endif
#define DECLARE(CLS,PCLS,PNODE,ELEM,PELEM) BOOL CLS##_empty(PCLS p);\
	BOOL CLS##_push_back(PCLS p,PELEM e);\
	size_t CLS##_size(PCLS p);\
	PCLS CLS##_create(int );\
	void CLS##_destory(PCLS p);\
	void CLS##_erase(PCLS p,PNODE _Where);\
	PNODE CLS##_find(PCLS p,PELEM e);\
	PNODE CLS##_begin(PCLS p);\
	PNODE CLS##_end(PCLS p);\
	PNODE CLS##_rbegin(PCLS p);\
	PNODE CLS##_rend(PCLS p);\
	BOOL CLS##_increase(PNODE* p);\
	BOOL CLS##_decrease(PNODE* p);\
	PELEM CLS##_newInt(int v);\
	PELEM CLS##_newString(const char* v);\
	void CLS##_delete(PELEM p);\
	int CLS##_intValue(PELEM e);

#define DECLARE_ELEM(CLS,ELEM,PELEM) \
	PELEM CLS##_newInt(int v){PELEM p = (PELEM)malloc(sizeof(ELEM));\
		p->data = (int*)malloc(sizeof(int));\
		*(int*)(p->data) = v;\
		p->size = sizeof(int);\
		return p;}\
	int CLS##_intValue(PELEM e){if(!e) return 0;return *(int*)e->data;}\
	PELEM CLS##_newString(const char* v){PELEM p = (PELEM)malloc(sizeof(ELEM));\
		size_t len = strlen(v);\
		p->data = (char*)malloc(len);\
		memcpy(p->data,v,len);\
		p->size = sizeof(int);\
		return p;}\
		void CLS##_delete(PELEM p){\
			free(p->data);\
			free(p);\
		}
#define METHOD(CLS,FUNC) CLS##FUNC
#endif