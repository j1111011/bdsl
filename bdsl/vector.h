/*
// Copyright (c) 2011-2012 
// 
// jl£¨ j1111011@163.com £©
 */
#ifndef _BSDL_VECTOR_H_
#define _BSDL_VECTOR_H_ 0x01
#include <stdlib.h>
#ifndef _BSDL_VECTOR_TYPE
#define _BSDL_VECTOR_TYPE int
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef struct __tagvectorelem{
	_BSDL_VECTOR_TYPE value;
}*pvectorelem,vectorelem;
struct __tagvectornode;
typedef struct __tagvectornode *pvectornode,vectornode;
typedef struct __tagvector{
	pvectornode (*create)(int max);
	void (*destory)(pvectornode );
	int (*push_back)(pvectornode ,pvectorelem );
	int (*erase)(pvectornode,size_t);
	int (*empty)(pvectornode );
	size_t (*find)(pvectornode,pvectorelem );
	size_t (*size)(pvectornode );
	pvectorelem (*at)(pvectornode,size_t );
}vector,*pvector;
pvector new_vector();
void delete_vector(pvector);
#ifdef __cplusplus
}
#endif
#endif ;
