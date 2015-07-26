/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include "adlist.h"

int main(int argc, char** argv){
	list *lt = listCreate();
	listAddNodeHead(lt, "Hello");
	listAddNodeHead(lt, "world");
	int value = 123;
	listAddNodeTail(lt, &value);

	if(lt){
		printf("%s\n", (char*)listNodeValue(listIndex(lt, 0)));
		printf("%s\n", (char*)listNodeValue(listIndex(lt, 1)));
		printf("%d\n", *(int*)listNodeValue(listIndex(lt, 2)));
	}
	listRelease(lt);
	return 0;
}
#endif

