/*
// Copyright (c) 2011-2012 
// 
// jl£¨ j1111011@163.com £©
 */
#ifndef _BSDL_QUEUE_H_
#define _BSDL_QUEUE_H_ 0x01
#include <stdlib.h>
#ifdef __cplusplus
extern "C" { 
#endif
typedef struct __tagqueueelem{
	int value;
}*pqueueelem,queueelem;
struct __tagqueuenode;
typedef struct __tagqueuenode *pqueuenode,queuenode;
typedef struct __tagqueue{
	pqueuenode (*create)();
	void (*destory)(pqueuenode );
	int (*push)(pqueuenode ,pqueueelem );
	void (*pop)(pqueuenode);
	pqueueelem (*front)(pqueuenode);
	int (*empty)(pqueuenode );
	size_t (*size)(pqueuenode );
}queue,*pqueue;
extern pqueue new_queue();
extern void delete_queue(pqueue);
#ifdef __cplusplus
} 
#endif //end cplusplus
#endif
