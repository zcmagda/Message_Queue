#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <stdio.h>

struct buf {
	long type;
	char value[20];
}word;

int main() {

	key_t key;
	int wordID;

	printf("Enter the word: ");
	scanf("%s",word.value);
	word.type=1;
	
	if ((key=ftok("./send",'b')) == -1) {
		perror("ftok");
		exit(1);
	}

	
	if ((wordID=msgget(key,0600 | IPC_CREAT)) == -1) {
		perror("msgget");
		exit(1);
	}

	if(msgsnd(wordID,&word,sizeof(word.value),IPC_NOWAIT) == -1)
		perror("msgsend");

return 0;
}
