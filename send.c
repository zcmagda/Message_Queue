#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <stdio.h>

struct buf {
	long mtype;
	char mvalue[20];
}word;

#define cool_msg  

int main() {

	word.mtype=cool_msg;

	printf("Enter the word: ");
	scanf("%s",word.mvalue);

	int wordID=msgget(,IPC_CREAT | 0600);

	if (wordID==-1) {
		perror("msgget");
	}
	
return 0;
}
