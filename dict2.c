#include <rpc/rpc.h>
#include "rdict.h"
#include <string.h>

item pool[DICTSIZ];
int nwords = 0;
int id = 0;
int stat = 0;

int initw()
{
    nwords = 0;
    id = 0;
    return 1;
}

int insertw(char *word)
{
    pool[nwords].id = ++id;
    strcpy(pool[nwords].sn, word);
    pool[nwords].stat = stat;
    nwords++;
    return nwords;
}

int deletew(int id)
{
    int i;
    for(i=0; i<nwords; i++){
	if(pool[i].id == id){
	    nwords--;
	    pool[i] = pool[nwords];
	    return 1;
	}
    }
    return 0;
}

int lookupw(char *word)
{
    int i;
    for(i=0; i<nwords; i++)
	if(strcmp(word, pool[i].sn) == 0)
	    return 1;
    return 0;
}

item lsw()
{
    static int i = 0;
    item it;
    
    it.id = pool[i].id;
    strcpy(it.sn, pool[i].sn);
    it.stat = pool[i].stat;
    i++;
    if(i > nwords){
	i = 0;
	it.id = 0;
    }
    return it; 
}

int setw(int id)
{
    int i;
    for(i=0; i<nwords; i++){
	if(pool[i].id == id){
	    pool[i].stat = (pool[i].stat+1) % 2;
	    return 1;
	}
    }
    return 0;
}
