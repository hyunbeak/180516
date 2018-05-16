#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
int fd;
void sigHandler(int sig){
		 int byteCount;
		 char buffer[255];
		 time_t current_time;
		 time(&current_time);


	printf("take a Handling %d\n",sig);
	sprintf(buffer,"%s //%d \n",ctime(&current_time),sig);
	byteCount=write(fd,buffer,strlen(buffer));
	printf("%d\n",byteCount);
}

int main(void){
		int a=0;
	signal(SIGUSR1,sigHandler);
	signal(SIGUSR2,sigHandler);
	signal(SIGINT,sigHandler);
	 fd=open("./log.txt",O_RDWR|O_CREAT|O_TRUNC,\
					 S_IRWXU|S_IWGRP|S_IRUSR|S_IRGRP|S_IROTH);

	while(a<10){
	
			pause();
			a++;
	}
	
	close(fd);
	return 0;
}
