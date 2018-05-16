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
	pause;
	return 0;
}
