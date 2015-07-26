/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include  <string.h>
#include "zmalloc.h"
typedef struct dict {
    void *privdata;
    long rehashidx; /* rehashing not in progress if rehashidx == -1 */
    int iterators; /* number of iterators currently running */
} dict;

int main(int argc, char** argv){
	dict* d = zmalloc(sizeof(*d));
	d->iterators = 123;
	printf("%d\n", d->iterators);
	zfree(d);
	return 0;
}
#endif

