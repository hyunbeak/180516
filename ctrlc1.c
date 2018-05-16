#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void sigHandler(int sig){
	static int cnt =0;
	printf("OUCH! - i got signal %d\n",sig);
	cnt ++;
	if(cnt==5)
	//(void)signal(SIGINT,SIG_DFL);
	(void)signal(SIGQUIT,SIG_DFL);

}

int main(void){
	//if(signal(SIGINT,sigHandler)==SIG_ERR){
	if(signal(SIGQUIT,sigHandler)==SIG_ERR){//ctrl + \
			printf("perror\n");
			exit(-1);
	}
			while(1){
			printf("Hello World!\n");
			sleep(5);
			}
	return 0;
}
