#ifndef _BSDL_MAP_H_
#define _BSDL_MAP_H_ 0x01
#include <stdlib.h>
#ifndef _BSDL_MAP_KEY_TYPE
#define _BSDL_MAP_KEY_TYPE int
#endif
#ifndef _BSDL_MAP_VALUE_TYPE
#define _BSDL_MAP_VALUE_TYPE int
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef struct __tagmapelem{
	_BSDL_MAP_KEY_TYPE key;
	_BSDL_MAP_VALUE_TYPE value;
}*pmapelem,mapelem;
struct __tagmapnode;
typedef struct __tagmapnode *pmapnode,mapnode;
typedef struct __tagmap{
	pmapnode (*create)();
	void (*destory)(pmapnode );
	int (*insert)(pmapnode ,pmapelem );
	int (*erase)(pmapnode,_BSDL_MAP_KEY_TYPE );
	int (*empty)(pmapnode );
	pmapelem (*find)(pmapnode,_BSDL_MAP_KEY_TYPE );
	size_t (*size)(pmapnode );
}map,*pmap;
extern pmap new_map();
extern void delete_map(pmap);
extern pmapelem mappair(_BSDL_MAP_KEY_TYPE key,_BSDL_MAP_VALUE_TYPE value);

#ifdef __cplusplus
}
#endif
#endif ;
