#include <rpc/rpc.h>
#include "rdict.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAXWORD 50
#define RMACHINE "localhost"
CLIENT *handle;

int nextin(char *cmd, char *word), initw(void), insertw(char *),
    deletew(int), lookupw(char *);
item lsw(void);

int main(int argc, char *argv[])
{
    char word[MAXWORD+1];
    char cmd;
    int wrdlen;
    item li;

    handle = clnt_create(RMACHINE, RDICTPROG, RDICTVERS, "tcp");
    if(handle == 0){
	printf("Could not contact remote program.\n");
	exit(1);
    }

    while(1){
	wrdlen = nextin(&cmd, word);
	if(wrdlen < 0)
	    exit(0);
	switch(cmd){
	case 'I':
	    initw();
	    printf("Dictionary initialized to empty.\n");
	    break;
	case 'i':
	    insertw(word);
	    printf("%s inserted.\n", word);
	    break;
	case 'd':
	    if(deletew(atoi(word)))
		printf("%d deleted.\n", atoi(word));
	    else
		printf("%d not found.\n", atoi(word));
	    break;
	case 'l':
	    if(lookupw(word))
		printf("%s was found.\n", word);
	    else
		printf("%s was not found.\n", word);
	    break;
	case 'L':
	    while(1){
		li = lsw();
		if(li.id == 0){
		    printf("Show all.\n");
		    break;
		}
		printf("item %d: %s, status->%d\n", li.id, li.sn, li.stat);
	    }
	    break;
	case 's':
	    if(setw(atoi(word))){
		printf("Set %d OK.\n", atoi(word));
	    }else{
		printf("Set %d fail.\n", atoi(word));
	    }
	    break;
	case 'q':
	    printf("Program quits.\n");
	    exit(0);
	default:
	    printf("Command %c invalid.\n", cmd);
	    break;
	}
    }
}

int nextin(char *cmd, char *word)
{
    int i, ch;
    ch = getc(stdin);
    while(isspace(ch))
	ch = getc(stdin);
    if(ch == EOF)
	return -1;
    *cmd = (char) ch;
    ch = getc(stdin);
    while(isspace(ch)){
	if(ch == '\n')
	    return 0;
	ch = getc(stdin);
    }
    if(ch == EOF)
	return -1;
    i = 0;
    while(!isspace(ch)){
	if(++i > MAXWORD){
	    printf("Error: word too long.\n");
	    exit(1);
	}
	*word++ = ch;
	ch = getc(stdin);
    }
    *word = '\0';
    return i;
}
