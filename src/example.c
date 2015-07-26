/*
 * ae_test.c
 *
 *  Created on: 2015-7-20
 *      Author: liufuliang
 */
#if 0
#include "ae.h"

int bigEndian() {
	union w {char byte[2]; int v;} value;
	value.v = 1;
	return (value.byte[0] == 0);
}

int main (int argc, char **argv) {
	aeEventLoop *loop = aeCreateEventLoop(64);
	aeMain(loop);
	return 0;
}
#endif
