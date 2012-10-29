#include <string.h>

#include "list.h"
DECLARE_ELEM(list,ListElem,PListElem);
plist METHOD(list,_create)(int alloc){
	plist lst = (plist)malloc(sizeof(list));
	lst->header = (PListNode)malloc(sizeof(ListNode));
	lst->header->_next = NULL;
	lst->header->_prev = NULL;
	memset(lst->header,0,sizeof(ListNode));
	lst->trailer = (PListNode)malloc(sizeof(ListNode));
	memset(lst->trailer,0,sizeof(ListNode));
	lst->size = 0;
	lst->max = alloc;
	return	lst;
}
BOOL METHOD(list,_empty)(plist p){
	return p->size == 0;
}
BOOL METHOD(list,_push_back)(plist p,PListElem e){
	PListNode node = p->trailer->_prev;
	PListNode newNode = NULL;
	if(p->max != 0 && p->size >= p->max){
		return	FALSE;
	}
	newNode = (PListNode)malloc(sizeof(ListNode));
	memset(newNode,0,sizeof(ListNode));
	newNode->_elem = malloc(sizeof(ListNode));
	newNode->_elem->data = malloc(e->size);
	memcpy(newNode->_elem->data,e->data,e->size);
	if(p->size == 0){
		p->header->_next = newNode;
		newNode->_prev = p->header;
		newNode->_next = p->trailer;
		p->trailer->_prev = newNode;
		p->size ++;
		return	TRUE;
	}
	newNode->_prev = node;	
	newNode->_next = p->trailer;
	node->_next = newNode;		
	p->trailer->_prev = newNode;
	p->size++;
	return	TRUE;
}
size_t METHOD(list,_size)(plist p){
	return p->size;
}
void METHOD(list,_destory)(plist p){
	free(p);
}
void METHOD(list,_erase)(plist p,PListNode _Where){
	if(p->size == 0){
		return	;
	}
	_Where->_prev->_next = _Where->_next;
	if(_Where->_next){
		_Where->_next->_prev = _Where->_prev;
	}
	p->size --;
	free(_Where->_elem->data);
	free(_Where->_elem);
	free(_Where);
}
PListNode METHOD(list,_find)(plist p,PListElem e){
	PListNode iter = NULL;
	for(iter = p->header;iter != p->trailer;iter = iter->_next){
		if(iter->_elem == NULL){
			continue;
		}
		if(0 == memcmp(e->data,iter->_elem->data,e->size > iter->_elem->size ? iter->_elem->size : e->size)){
			return	iter;
		}
	}
	return	0;
}

PListNode METHOD(list,_begin)(plist p){
	return p->header->_next;
}
PListNode METHOD(list,_end)(plist p){
	return p->trailer;
}
PListNode METHOD(list,_rbegin)(plist p){
	return	p->trailer->_prev;
}
PListNode METHOD(list,_rend)(plist p){
	return p->header;
}
BOOL METHOD(list,_increase)(PListNode* p){
	if(*p){
		*p = (*p)->_next;
		return TRUE;
	}
	return	FALSE;
}
BOOL METHOD(list,_decrease)(PListNode* p){
	if(*p){
		*p = (*p)->_prev;
		return TRUE;
	}
	return FALSE;
}