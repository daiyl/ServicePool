const MAXWORD = 50;
const DICTSIZ = 100;

struct item{
    int id;
    char sn[MAXWORD];
    int stat;
};

program RDICTPROG{
    version RDICTVERS{
	int INITW(void) = 1;
	int INSERTW(string) = 2;
	int DELETEW(int) = 3;
	int LOOKUPW(string) = 4;
	item LSW(void) = 5;
	int SETW(int) = 6;
    } = 1;
} = 0x30090949;
