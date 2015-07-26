/*
 * intset_test.c
 *
 *  Created on: 2015-7-23
 *      Author: liufuliang
 */


#if 0
#include <stdio.h>
#include "intset.h"

void intsetPrint(intset *set){
	for(int i=0; i<intsetLen(set); ++i){
		int64_t value;
		intsetGet(set, i, &value);
		printf("SET value: %ld\n", value);
	}
}


int main(int argc, char** argv){
	printf("INTSET size: %ld\n", sizeof(intset));
	intset *set = intsetNew();
	set = intsetAdd(set, 1234, NULL);
	set = intsetAdd(set, 12345, NULL);
	set = intsetAdd(set, 1, NULL);
	set= intsetAdd(set, 2, NULL);
	set = intsetAdd(set, 123456789, NULL);
	printf("SET find: %d\n", intsetFind(set, 1234));
	printf("SET find: %d\n", intsetFind(set, 234));
	printf("SET find: %d\n", intsetFind(set, 123456789));
	printf("SET find: %d\n", intsetFind(set, 1));
	printf("SET find: %d\n", intsetFind(set, 2));
	printf("INTSET size: %ld\n", sizeof(intset));
	printf("SET size: %ld\n", sizeof(set));
	printf("SET size: %d\n", intsetLen(set));
	intsetPrint(set);


	set = intsetRemove(set, 12345, NULL);
	intsetPrint(set);

	for(int i=0; i<1024; ++i){
		set = intsetAdd(set, i, NULL);
	}

//	zfree(set->contents);
//	zfree(set);

	set = intsetNew();
	set = intsetAdd(set, 1234, NULL);
//	intsetAdd(set, 12345, NULL);
	intsetPrint(set);

	return 0;
}
#endif



