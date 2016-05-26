#include <stdlib.h>
#include <sys/msg.h>
#include <stdio.h>

struct buf {
	long type;
	char value[20];
}word;

int main() {

	key_t key;
	int wordID;
	
	if ((key=ftok("./send",'b')) == -1) {
		perror("ftok");
		exit(1);
	}
	
	if ((wordID=msgget(key,0600)) == -1) {
		perror("msgget");
		exit(1);
	}

	if (msgrcv(wordID,&word,sizeof(word.value),1,IPC_NOWAIT) == -1) {
		perror("msgrcv");
		exit(1);
	}
	
return 0;
}
