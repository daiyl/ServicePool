#include <rpc/rpc.h>
#include <stdio.h>
#define RPC_CLNT
#include "rdict.h"

extern CLIENT *handle;
static int *ret;
static item *li;

int initw()
{
    ret = initw_1(0, handle);
    return ret==0 ? 0 : *ret;
}

int insertw(char *word)
{
    char **arg;
    arg = &word;
    ret = insertw_1(arg, handle);
    return ret==0 ? 0 : *ret;
}

int deletew(int id)
{
    int *arg;
    arg = &id;
    ret = deletew_1(arg, handle);
    return ret==0 ? 0 : *ret;
}

int lookupw(char *word)
{
    char **arg;
    arg = &word;
    ret = lookupw_1(arg, handle);
    return ret==0 ? 0 : *ret;
}

item lsw()
{
    li = lsw_1(0, handle);
    return *li;
}

int setw(int id)
{
    int *arg;
    arg = &id;
    ret = setw_1(arg, handle);
    return ret==0 ? 0 : *ret;
}
