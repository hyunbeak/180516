#include<signal.h>
#include "tlpi_hdr.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
static void sigHandler(int sig){
	static int count = 0;
	{
	count++;
	printf("Caught SIGINT (%d)\n",count);
	return ;
	}

	printf("Caught DIGQUIT - that's all folks!\n");
	exit(0);
}

int main(int argc,char *argv[]){
	if(signal(SIGINT,sigHandler)== SIG_ERR)
			//errExit(-1);
			return -1;
	if(signal(SIGQUIT,sigHandler)==SIG_ERR)
			//errExit(-1);
			return-1;
	for(;;)
			/*signal이 들어올 때 까지 무한적으로blocking 상태 */
			/*터미널에서 kill -9 pid 번호 -9는 sig번호 (sigkill번호)*/	
		pause;
	return 0;
}
