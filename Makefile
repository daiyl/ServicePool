CFLAGS =	#-g & {INCLUDE}
SRC = 		dict1.c dict2.c rdict_x rdict_cif.c rdict_sif.c rdict_cif.c

PROGS = 	dict_clnt rdictd

GFILES = 	rdict.h rdict_clnt.c rdict_svc.c rdict_xdr.c

DICT_CLNT_OBJ = rdict_clnt.o rdict_cif.o dict1.o
RDICTD_OBJ = 	rdict_svc.o rdict_sif.o dict2.o

all:		rdict.h ${PROGS} 

install:	all
		@echo nothing to install.
clean:
		rm *.o ${PROGS} ${GFILES}

#${GFILES}:	rdict.h
rdict.h:	rdict.x
		rpcgen rdict.x

${DICT_CLNT_OBJ}:
		${CC} ${CFLAGS} -c $*.c
dict_clnt:	${DICT_CLNT_OBJ} rdict_xdr.o
		${CC} ${CFLAGS} -o $@ ${DICT_CLNT_OBJ} rdict_xdr.o
		chmod 755 dict_clnt

${RDICTD_OBJ}:
		${CC} ${CFLAGS} -c $*.c
rdictd:		${RDICTD_OBJ} rdict_xdr.o
		${CC} ${CFLAGS} -o $@ ${RDICTD_OBJ} rdict_xdr.o
		chmod 755 rdictd

rdict_xdr.o:
		${CC} ${CFLAGS} -c $*.c
