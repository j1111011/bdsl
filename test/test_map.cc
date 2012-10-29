#include "../bdsl/map.h"
#include <gtest/gtest.h>
TEST(MapTest,createMap)
{
	pmap map = new_map();
	pmapnode root = map->create();
	ASSERT_TRUE(map->empty(root));
	map->destory(root);
	delete_map(map);
}
TEST(MapTest,mapInsert)
{
	try{
		pmap map = new_map();
		pmapnode root = map->create();
		for(int it = 0;it != 0xfff;++it){
			mapelem elem;
			elem.key = it;
			elem.value = it + 0xfff;
			map->insert(root,&elem);
		}
		ASSERT_TRUE(map->size(root) == 0xfff);
		ASSERT_TRUE(map->find(root,18)->value == 18 + 0xfff);
		ASSERT_TRUE(map->insert(root,mappair(18,88)) == 0);
		ASSERT_TRUE(map->find(root,18)->value == 88);
		map->destory(root);
		delete_map(map);
	}catch(std::exception& e){
		std::cout <<e.what()<<std::endl;
	}catch(...){
		std::cout <<"Unkown Exception"<<std::endl;
	}
	
}
TEST(MapTest,mapErase)
{
	pmap map = new_map();
	pmapnode root = map->create();
	ASSERT_TRUE(map->empty(root));
	mapelem elem;
	elem.key = 33;
	elem.value = 48;
	map->insert(root,&elem);
	ASSERT_TRUE(1 == map->size(root));
	elem.key = 48;
	elem.value = 720;
	map->insert(root,&elem);
	ASSERT_TRUE(2 == map->size(root));
	ASSERT_TRUE(map->erase(root,33) == 0);
	ASSERT_TRUE(map->erase(root,33) == -1);
	ASSERT_TRUE(map->find(root,48)->value == 720);
	map->destory(root);
	delete_map(map);
	
}