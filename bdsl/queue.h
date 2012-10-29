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
	int (*push_back)(pqueuenode ,pqueueelem );
	int (*erase)(pqueuenode,size_t);
	int (*empty)(pqueuenode );
	size_t (*find)(pqueuenode,pqueueelem );
	size_t (*size)(pqueuenode );
	pqueueelem (*at)(pqueuenode,size_t );
}queue,*pqueue;
extern pqueue new_queue();
extern void delete_queue(pqueue);
#ifdef __cplusplus
} 
#endif //end cplusplus
#endif ;
