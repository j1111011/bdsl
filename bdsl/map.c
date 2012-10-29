#include "map.h"
#include <string.h>
#include <limits.h>
#define MAP_RIGHT 0
#define MAP_LEFT 1
#define MAP_ROOT 2
typedef struct __tagmapnode{
	mapelem _elem;
	struct __tagmapnode* _parent;
	struct __tagmapnode* _left;
	struct __tagmapnode* _right;
	unsigned char _role;
	unsigned int _size;
}*pmapnode,mapnode;
pmapnode map_create(){
	pmapnode root = malloc(sizeof(mapnode));
	memset(root,0,sizeof(mapnode));
	root->_role = MAP_ROOT;
	return root;
}
void map_destory(pmapnode header){

}
void _increase_M_count(pmapnode node){
	pmapnode _x = node;
	while(_x->_parent != NULL){
		_x = _x->_parent;
	}
	_x->_size++;
}
void _decrease_M_count(pmapnode node){
	pmapnode _x = node;
	while(_x->_parent != NULL){
		_x = _x->_parent;
	}
	_x->_size--;
}
int map_empty(pmapnode header);
int map_insert(pmapnode header,pmapelem elem){
	if(elem->key > header->_elem.key){
		if(header->_right != NULL){
			return map_insert(header->_right,elem);
		}
		else {
			pmapnode node = map_create();
			node->_elem = *elem;
			node->_parent = header;
			header->_right = node;
			node->_role = MAP_RIGHT;
		}
	}
	else if(elem->key < header->_elem.key){
		if(header->_left != NULL){
			return map_insert(header->_left,elem);
		}
		else {
			pmapnode node = map_create();
			node->_elem = *elem;
			node->_parent = header;
			header->_left = node;
			node->_role = MAP_LEFT;
		}
	}
	else if(elem->key == header->_elem.key){
		header->_elem.value = elem->value;
	}
	_increase_M_count(header);
	return 0;
}

void _map_free( pmapnode header ) 
{
	if(header->_role != MAP_ROOT){
		free(header);
	}
	
}

int map_erase(pmapnode header,_BSDL_MAP_KEY_TYPE elem){
	if(elem > header->_elem.key){
		if(header->_right != NULL){
			return map_erase(header->_right,elem);
		}
	}
	else if(elem < header->_elem.key){
		if(header->_left != NULL){
			return map_erase(header->_left,elem);
		}
	}
	else if(elem == header->_elem.key){

		if(header->_left == NULL && header->_right == NULL){//没有子树

		}
		else if(header->_left == NULL && header->_right != NULL){//右子树存在
			if(header->_role == MAP_LEFT){
				header->_parent->_left = header->_right;
				header->_right->_role = MAP_LEFT;
			}
			else if(header->_role == MAP_RIGHT){
				header->_parent->_right = header->_right;
			}
		}
		else if(header->_left != NULL && header->_right == NULL){//右子树存在
			if(header->_role == MAP_LEFT){
				header->_parent->_left = header->_left;
			}
			else if(header->_role == MAP_RIGHT){
				header->_parent->_right = header->_left;
				header->_left->_role = MAP_RIGHT;
			}
		}
		else {//子树都存在
			pmapnode _x = header->_left;
			while(_x->_left){
				_x = _x->_left;
			}
			_x->_parent->_left = _x->_right;
			_x->_left = header->_left;
			_x->_right = header->_right;
			_x->_parent = header->_parent;
			if(header->_role == MAP_RIGHT){
				header->_parent->_right = _x;
			}
			else {
				header->_parent->_left = _x;
			}

			_x->_role = MAP_RIGHT;
		}
		_decrease_M_count(header);
		_map_free(header);		
		return	0;
	}
	return	-1;
}
int map_empty(pmapnode header){
	return header->_size == 0;
}
pmapelem map_find(pmapnode header,_BSDL_MAP_KEY_TYPE elem){
	if(elem > header->_elem.key){
		if(header->_right != NULL){
			return map_find(header->_right,elem);
		}
	}
	else if(elem < header->_elem.key){
		if(header->_left != NULL){
			return map_find(header->_left,elem);
		}
	}
	else if(elem == header->_elem.key){
		return &header->_elem;
	}
	return	0;
}
size_t map_size(pmapnode header){
	return header->_size;
}
pmap new_map(){
  pmap node = malloc(sizeof(map));
  node->create = &map_create;
  node->destory = &map_destory;
  node->insert = &map_insert;
  node->erase = &map_erase;
  node->find = &map_find;
  node->size = &map_size;
  node->empty = &map_empty;
  return node;
}
void delete_map(pmap lst ){ free(lst);};

mapelem __temporary;
pmapelem mappair( _BSDL_MAP_KEY_TYPE key,_BSDL_MAP_VALUE_TYPE value )
{
	__temporary.key = key;
	__temporary.value = value;
	return &__temporary;
}
