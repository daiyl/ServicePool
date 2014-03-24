#include <rpc/rpc.h>
#define RPC_SVC
#include "rdict.h"

static int retcode;
static item li;
int initw(void), insertw(char *), deletew(int), lookupw(char *), setw(int);
item lsw(void);

int * insertw_1_svc(char **w, struct svc_req *rqstp)
{
    retcode = insertw(*(char **)w);
    return &retcode;
}

int * initw_1_svc(void *w, struct svc_req *rqstp)
{
    retcode = initw();
    return &retcode;
}

int * deletew_1_svc(int *id, struct svc_req *rqstp)
{
    retcode = deletew(*(int *)id);
    return &retcode;
}

int * lookupw_1_svc(char **w, struct svc_req *rqstp)
{
    retcode = lookupw(*(char **)w);
    return &retcode;
}

item * lsw_1_svc(void *w, struct svc_req *rqstp)
{
    li = lsw();
    return &li;
}

int * setw_1_svc(int *id, struct svc_req *rqstp)
{
    retcode = setw(*(int *)id);
    return &retcode;
}
