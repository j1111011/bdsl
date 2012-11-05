#include "queue.h"
#include <string.h>
typedef struct __tagqueuenode{
	queueelem elem;
	size_t size;
	struct __tagqueuenode* _fronter;
	struct __tagqueuenode* _tailer;
	struct __tagqueuenode* _next;
}*pqueuenode,queuenode;
pqueuenode queue_create(){
	pqueuenode node = (pqueuenode)malloc(sizeof(queuenode));
	memset(node,0,sizeof(queuenode));
	return node;
}
int queue_push(pqueuenode header,pqueueelem elem){
	pqueuenode node = queue_create();
	if(header->_tailer == NULL){
		header->_tailer = node;
		header->_fronter = node;
		node->elem = *elem;
	}
	else {
		header->_tailer->_next = node;
		header->_tailer = node;
		node->elem = *elem;
	}
	header->size++;
	return 0;
}
void queue_pop(pqueuenode header){
	pqueuenode _x = header->_fronter;
	if(header->size == 0){
		return	;
	}
	if(_x != NULL){
		header->_fronter = _x->_next;
		if(header->_tailer == _x){
			header->_tailer = NULL;
		}
		free(_x);
	}
	header->size--;
}

int queue_empty(pqueuenode header){
	return header->_fronter == NULL;
}
pqueueelem queue_front(pqueuenode header){
	if(!queue_empty(header)){
		return	&header->_fronter->elem;
	}
	return	0;
}
void queue_destory(pqueuenode header){
	while(!queue_empty(header)){
		queue_pop(header);
	}
	free(header);
}
size_t queue_size(pqueuenode header){
	return header->size;
}
pqueue new_queue(){
  pqueue node = malloc(sizeof(queue));
  node->create = &queue_create;
  node->destory = &queue_destory;
  node->push = &queue_push;
  node->pop = &queue_pop;
  node->front = &queue_front;
  node->size = &queue_size;
  node->empty = &queue_empty;
  return node;
}
void delete_queue(pqueue lst ){ 
	free(lst);
};
