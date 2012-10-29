#include "queue.h"
typedef struct __tagqueuenode{
	queueelem elem;
}*pqueuenode,queuenode;
pqueuenode queue_create(){return NULL;}
void queue_destory(pqueuenode header){}
int queue_push_back(pqueuenode header,pqueueelem elem){return 0;}
int queue_erase(pqueuenode header,size_t index){return	0;}
int queue_empty(pqueuenode header){return 0;}
size_t queue_find(pqueuenode header,pqueueelem elem){return 0;}
size_t queue_size(pqueuenode header){return 0;}
pqueueelem queue_at(pqueuenode header,size_t index){return 0;}
pqueue new_queue(){
  pqueue node = malloc(sizeof(queue));
  node->create = &queue_create;
  node->destory = &queue_destory;
  node->push_back = &queue_push_back;
  node->erase = &queue_erase;
  node->find = &queue_find;
  node->size = &queue_size;
  node->empty = &queue_empty;
  node->at = &queue_at;
  return node;
}
void delete_queue(pqueue lst ){ free(lst);};
