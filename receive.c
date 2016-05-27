#include <stdlib.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

struct buf {
	long type;
	char value[20];
}word;

int main() {

	time_t mytime;
	struct tm *mytm;
	mytime=time(NULL);
	mytm=localtime(&mytime);

	if((mytm->tm_wday == 5) || (mytm->tm_wday == 6) || (mytm->tm_wday == 0)) {	

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

		char *arg[2];
		arg[0]="./verify.sh";
		arg[1]=word.value;
		
		execvp(arg[0], arg);
	}

	else
		printf("I only work on weekends\n");
	
return 0;
}
