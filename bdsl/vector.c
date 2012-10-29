#include "vector.h"
#include <string.h>
#include <stdlib.h>
typedef struct __tagvectornode{
	pvectorelem elements;
	size_t max;
	size_t cur;
	size_t allocate;
	char empty;
}*pvectornode,vectornode;

pvectornode vector_create(int max){
	pvectornode node = malloc(sizeof(vectornode));
	node->elements = malloc(sizeof(vectorelem)* max);
	node->max = max;
	node->allocate = max;
	node->cur = 0;
	node->empty = 1;
	return node;
}
void vector_destory(pvectornode header){
	free(header->elements);
	free(header);
}
int vector_push_back(pvectornode header,pvectorelem elem){
	if(header->max == header->cur){
		pvectorelem newer = malloc(sizeof(vectorelem)*(header->max + header->allocate));
		memcpy(newer,header->elements,header->max*sizeof(vectorelem));
		free(header->elements);
		header->elements = newer;
		header->max += header->allocate;
		header->elements[header->cur++] = *elem;
	}
	else {
		header->elements[header->cur++] = *elem;
	}
	return 0;
}
void _vector_Copy_(pvectornode header,size_t new_,size_t size){
	memcpy(&header->elements[new_],&header->elements[new_ + 1],size);
}
void _vector_Destory_(pvectornode header,size_t index){

}
int vector_erase(pvectornode header,size_t index){
	if(header->cur >= index){
		_vector_Copy_(header,index,header->max - index);
		_vector_Destory_(header,index);
		header->cur--;
	}
	return	-1;
}
int vector_empty(pvectornode header){
	return header->empty;
}
size_t vector_find(pvectornode header,pvectorelem elem){
	int it = 0;
	for(it = 0;it != header->cur;it++){
		if(header->elements[it].value == elem->value){
			return	it;
		}
	}
	return -1;
}
size_t vector_size(pvectornode header){
	return header->cur;
}
pvectorelem vector_at(pvectornode header,size_t index){
	if(header->cur >= index){
		return	&(header->elements[index]);
	}
	return NULL;
}
pvector new_vector(){
  pvector node = malloc(sizeof(vector));
  node->create = &vector_create;
  node->destory = &vector_destory;
  node->push_back = &vector_push_back;
  node->erase = &vector_erase;
  node->find = &vector_find;
  node->size = &vector_size;
  node->empty = &vector_empty;
  node->at = &vector_at;
  return node;
}
void delete_vector(pvector lst ){
	free(lst);
};
