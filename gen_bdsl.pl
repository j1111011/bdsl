#!/bin/env perl
my @templates = ('list','vector','map','stack','queue');
foreach $tmp(@templates){
	print $tmp;
	open(hFile,'>'.'out/'.$tmp.'.h');
	open(sFile,'>'.'out/'.$tmp.'.c');
	my $header = '#ifndef _BSDL_'.uc($tmp).'_H_'."\n"
				.'#define _BSDL_'.uc($tmp).'_H_ 0x01'."\n"
				.'#include <stdlib.h>'."\n"
				.'#ifdef __cplusplus'."\n"
				.'extern "C" { '."\n"
				.'#endif'."\n"
				.'typedef struct __tag'.$tmp.'elem{'
				.'}*p'.$tmp.'elem,'.$tmp.'elem'.";\n"
				.'struct __tag'.$tmp.'node'.";\n"
				.'typedef struct __tag'.$tmp.'node *p'.$tmp.'node,'.$tmp.'node'.";\n"
				.'typedef struct __tag'.$tmp.'{'."\n"
				."\tp".$tmp.'node (*create)()'.";\n"
				."\t".'void (*destory)(p'.$tmp.'node )'.";\n"
				."\t".'int (*push_back)(p'.$tmp.'node ,p'.$tmp.'elem )'.";\n"
				."\t".'int (*erase)(p'.$tmp.'node,size_t)'.";\n"
				."\t".'int (*empty)(p'.$tmp.'node )'.";\n"
				."\t".'size_t (*find)(p'.$tmp.'node,p'.$tmp.'elem )'.";\n"
				."\t".'size_t (*size)(p'.$tmp.'node )'.";\n"
				."\t".'p'.$tmp.'elem (*at)(p'.$tmp.'node,size_t )'.";\n"
				.'}'.$tmp.',*p'.$tmp.";\n"
				.'extern p'.$tmp." new_".$tmp."();\n"
				.'extern void delete_'.$tmp.'(p'.$tmp.");\n"
				.'#ifdef __cplusplus'."\n"
				.'} '."\n"
				.'#endif //end cplusplus'."\n"
				.'#endif '.";\n";
	printf hFile $header;
	my $source = '#include "'.$tmp.'.h"'."\n"
				.'typedef struct __tag'.$tmp.'node{'."\n"
				.'}*p'.$tmp.'node,'.$tmp.'node'.";\n"
				.'p'.$tmp.'node '.$tmp.'_create(){return NULL;}'."\n"
				.'void '.$tmp.'_destory(p'.$tmp.'node header){}'."\n"
				.'int '.$tmp.'_push_back(p'.$tmp.'node header,p'.$tmp.'elem elem)'.'{return 0;}'."\n"
				.'int '.$tmp.'_erase(p'.$tmp.'node header,size_t index)'."{return	0;}\n"
				.'int '.$tmp.'_empty(p'.$tmp.'node header){return 0;}'."\n"
				.'size_t '.$tmp.'_find(p'.$tmp.'node header,p'.$tmp.'elem elem)'."{return 0;}\n"
				.'size_t '.$tmp.'_size(p'.$tmp.'node header)'."{return 0;}\n"
				.'p'.$tmp.'elem '.$tmp.'_at(p'.$tmp.'node header,size_t index)'."{return 0;}\n"
				.'p'.$tmp." new_".$tmp.'(){'."\n"
						.'  p'.$tmp.' node = malloc(sizeof('.$tmp.'));'."\n"
						.'  node->create = &'.$tmp.'_create'.";\n"
						.'  node->destory = &'.$tmp.'_destory'.";\n"
						.'  node->push_back = &'.$tmp.'_push_back'.";\n"
						.'  node->erase = &'.$tmp.'_erase'.";\n"
						.'  node->find = &'.$tmp.'_find'.";\n"
						.'  node->size = &'.$tmp.'_size'.";\n"
						.'  node->empty = &'.$tmp.'_empty'.";\n"
						.'  node->at = &'.$tmp.'_at'.";\n"
						.'  return node'.";\n"
						."}\n"
				.'void delete_'.$tmp.'(p'.$tmp." lst ){ free(lst);};\n";
	printf sFile $source;
	close(sFile);
	close(hFILE);
}
