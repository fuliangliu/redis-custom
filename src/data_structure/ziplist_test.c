/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include "ziplist.h"
#include "zmalloc.h"
#include <string.h>
#include <stdint.h>
int main(int argc, char** argv){

	unsigned char * zl = ziplistNew();

//	char smallv[1] = {'1'};
//	unsigned char *small_value = (unsigned char *)smallv;
	char midv[250];
	memset(midv, 'm', 250);
	unsigned char *mid_value = (unsigned char *)midv;
	char bigv[256];
	memset(bigv, 'b', 256);
	unsigned char *big_value = (unsigned char *)bigv;
	zl = ziplistPush(zl, mid_value, 250, ZIPLIST_HEAD);
	zl = ziplistPush(zl, mid_value, 250, ZIPLIST_TAIL);
	zl = ziplistPush(zl, mid_value, 250, ZIPLIST_TAIL);
	zl = ziplistPush(zl, mid_value, 250, ZIPLIST_TAIL);
	zl = ziplistPush(zl, mid_value, 250, ZIPLIST_TAIL);
	zl = ziplistPush(zl, mid_value, 250, ZIPLIST_TAIL);
	zl = ziplistPush(zl, big_value, 256, ZIPLIST_HEAD);
	printf("ZIPLIST LEN: %d\n", ziplistLen(zl));

	unsigned char *p = zl + 10;
	while(p){
		if(p[0] == 254){
			printf("%d\n", *((uint32_t*)(p+1)));
		}
		else{
			printf("%d\n", p[0]);
		}
		p = ziplistNext(zl, p);

	}

	zfree(zl);
	return 0;
}
#endif

