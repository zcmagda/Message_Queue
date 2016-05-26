#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <stdio.h>

struct buf {
	long type;
	char value[20];
}word;

#define cool_msg 100

int main() {

	word.type=cool_msg;
	
	printf("Enter the word: ");
	scanf("%s",word.value);

	key_t key=ftok("./send",'b');
	int wordID=msgget(key,IPC_CREAT | 0600);

	if (wordID == -1)
		perror("msgget failed");

	if(msgsnd(wordID,&word,sizeof(word.value),IPC_NOWAIT) == -1)
		perror("msgsend failed");
return 0;
}
