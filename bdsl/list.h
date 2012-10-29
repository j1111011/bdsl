#ifndef _BDSL_LIST_H
#define _BDSL_LIST_H 0x01
#include "base.h"
typedef struct __tagListElem{
	void* data;
	size_t size;
}ListElem,*PListElem;

typedef struct __tagListNode{
	struct __tagListNode* _prev;
	struct __tagListNode* _next;
	PListElem _elem;
}ListNode,*PListNode;

typedef struct __tagList
{
	PListNode header;
	PListNode trailer;
	size_t size;
	size_t max;
}list,*plist;
DECLARE(list,plist,PListNode,ListElem,PListElem)
#endif
