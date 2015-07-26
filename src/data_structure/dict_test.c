/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include  <string.h>
#include "dict.h"
#include "sds.h"
unsigned int dictSdsHash(const void *key) {
    return dictGenHashFunction((unsigned char*)key, sdslen((char*)key));
}
int dictSdsKeyCompare(void *privdata, const void *key1,
        const void *key2)
{
    int l1,l2;
    DICT_NOTUSED(privdata);

    l1 = sdslen((sds)key1);
    l2 = sdslen((sds)key2);
    if (l1 != l2) return 0;
    return memcmp(key1, key2, l1) == 0;
}
void dictSdsDestructor(void *privdata, void *val)
{
    DICT_NOTUSED(privdata);

    sdsfree(val);
}

void dictRedisObjectDestructor(void *privdata, void *val)
{
    DICT_NOTUSED(privdata);

    if (val == NULL) return; /* Values of swapped out keys as set to NULL */
    //decrRefCount(val);
}
/* Db->dict, keys are sds strings, vals are Redis objects. */
dictType dbDictType = {
    dictSdsHash,                /* hash function */
    NULL,                       /* key dup */
    NULL,                       /* val dup */
    dictSdsKeyCompare,          /* key compare */
    dictSdsDestructor,          /* key destructor */
    dictRedisObjectDestructor   /* val destructor */
};

int main(int argc, char** argv){
	dict *dict = dictCreate(&dbDictType,NULL);
	dictAdd(dict, sdsnew("key1"), sdsnew("value1"));
	dictEntry *entry = dictFind(dict, sdsnew("key1"));
	printf("%s, %s, %ld\n", (sds)entry->key, (sds)entry->v.val, dictSize(dict));

	dictAdd(dict, sdsnew("key2"), sdsnew("value2"));
	entry = dictFind(dict, sdsnew("key2"));
	printf("%s, %s, %ld\n", (sds)entry->key, (sds)entry->v.val, dictSize(dict));


	dictDelete(dict, sdsnew("key2"));
	entry = dictFind(dict, sdsnew("key2"));
	if(!entry){
		printf("No Find , %ld\n", dictSize(dict));
	}
	return 0;
}
#endif

