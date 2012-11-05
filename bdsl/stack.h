/*
// Copyright (c) 2011-2012 
// 
// jl£¨ j1111011@163.com £©
 */
#ifndef _BSDL_STACK_H_
#define _BSDL_STACK_H_ 0x01
#include <stdlib.h>
#ifdef __cplusplus
extern "C" { 
#endif
typedef struct __tagstackelem{
	int value;
}*pstackelem,stackelem;
struct __tagstacknode;
typedef struct __tagstacknode *pstacknode,stacknode;
typedef struct __tagstack{
	pstacknode (*create)();
	void (*destory)(pstacknode );
	int (*push_back)(pstacknode ,pstackelem );
	int (*erase)(pstacknode,size_t);
	int (*empty)(pstacknode );
	size_t (*find)(pstacknode,pstackelem );
	size_t (*size)(pstacknode );
	pstackelem (*at)(pstacknode,size_t );
}stack,*pstack;
extern pstack new_stack();
extern void delete_stack(pstack);
#ifdef __cplusplus
} 
#endif //end cplusplus
#endif ;
