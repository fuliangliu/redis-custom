/*
 * ae_test.c
 *
 *  Created on: 2015-7-20
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sha1.h"

#define BUFSIZE 4096

int main(int argc, char **argv)
{
    SHA1_CTX ctx;
    unsigned char hash[20], buf[BUFSIZE];
    int i;

    for(i=0;i<BUFSIZE;i++)
        buf[i] = i;

    SHA1Init(&ctx);
    for(i=0;i<1000;i++)
        SHA1Update(&ctx, buf, BUFSIZE);
    srand(time(NULL));
    int value = rand();
    SHA1Update(&ctx, (unsigned char*)&value, sizeof(value));
    SHA1Final(hash, &ctx);

    printf("SHA1=");
    for(i=0;i<20;i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}

#endif
