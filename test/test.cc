#include <stdio.h>
#include <gtest/gtest.h>
int	main(int argc,
		 char* argv[]){
	/*int it = 0;
	PListNode beg = NULL;
	plist lst = list_create(0);
	for(it = 0;it != 0xfff;++it){
		PListElem e = list_newInt(it + 8000);
		list_push_back(lst,e);
	}
	list_erase(lst,list_find(lst,list_newInt(8003)));
	for(beg = list_begin(lst);beg != list_end(lst);list_increase(&beg)){
		printf(" %d ",list_intValue(beg->_elem));
	}
	for(beg = list_rbegin(lst);beg != list_rend(lst);list_decrease(&beg)){
		printf(" %d ",list_intValue(beg->_elem));
	}*/
	/*vectorelem elem;
	vectorelem findelem; 
	pvectornode header;
	int it = 0;
	pvector vec = new_vector();
	header = NULL;
	//elem.value = 12;
	header = vec->create(10);
	for(it = 0;it != 0xffff;it++){
		elem.value = it;
		vec->push_back(header,&elem);
	}
	vec->erase(header,25);
	vec->erase(header,88);
	findelem.value = 230;
	vec->find(header,&findelem);
	for(it = 0;it != vec->size(header);it ++){
		printf(" %d\t",vec->at(header,it)->value);
	}
	vec->destory(header);
	delete_vector(vec);*/
			 testing::InitGoogleTest(&argc,argv);
			 return RUN_ALL_TESTS();
}