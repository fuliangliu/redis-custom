/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#include <stdio.h>
#include  <string.h>
#include "jemalloc/jemalloc.h"



int main(int argc, char** argv){
	int* array = (int*)je_malloc(10*sizeof(int));
	memset(array, 0, sizeof(array));
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	printf("sizeof array = %d\n", (int)sizeof(array));

	for(int index = 0; index < 10; ++index){
		printf("%d\n", array[index]);
	}
	je_free(array);
	return 0;
}


