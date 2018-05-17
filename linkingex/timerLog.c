#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

void MixArray(int n,int*Array){
	int numMix1=0,numMix2=0;
	int i=0,temp=0;

	for(i=0;i<1000;i++){
		numMix1 = rand()%n;
		numMix2 = rand()%n;
		printf("numMix1=%d,	numMix2=%d\n",numMix1,numMix2);
		fflush(stdout);
		temp=Array[numMix1];
		Array[numMix1]=Array[numMix2];
		Array[numMix2]=temp;
	}
}
int main(int argc,char* argv[]){
	pid_t pid;
	int fd,byteCount;
	int a=0;
	int value[2] ={SIGINT,SIGQUIT};
	pid=atoi(argv[1]);
	
	printf("%d",pid);
	srand(time(NULL));
	kill(pid,SIGUSR1);
	while(a<10){
		MixArray(2,value);
		kill(pid,value[0]);
		printf("%d, %d \n",value[0],pid);
		a++;
	}
	//sleep(2);
	kill(pid,SIGUSR2);
	return 0;
}

