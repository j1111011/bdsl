#include "stack.h"
typedef struct __tagstacknode{
	stackelem elem;
}*pstacknode,stacknode;
pstacknode stack_create(){return NULL;}
void stack_destory(pstacknode header){}
int stack_push_back(pstacknode header,pstackelem elem){return 0;}
int stack_erase(pstacknode header,size_t index){return	0;}
int stack_empty(pstacknode header){return 0;}
size_t stack_find(pstacknode header,pstackelem elem){return 0;}
size_t stack_size(pstacknode header){return 0;}
pstackelem stack_at(pstacknode header,size_t index){return 0;}
pstack new_stack(){
  pstack node = malloc(sizeof(stack));
  node->create = &stack_create;
  node->destory = &stack_destory;
  node->push_back = &stack_push_back;
  node->erase = &stack_erase;
  node->find = &stack_find;
  node->size = &stack_size;
  node->empty = &stack_empty;
  node->at = &stack_at;
  return node;
}
void delete_stack(pstack lst ){ free(lst);};
