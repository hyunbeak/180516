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
		 struct tm *tm;
		 time(&current_time);
	

	printf("take a signal [%d]",sig);
	//sprintf(buffer,"%s //%d \n",ctime(&current_time),sig);
	tm=localtime(&current_time);
	sprintf(buffer,"time = %s \n sig=[%d]\n",asctime(tm),sig);
	byteCount=write(fd,buffer,strlen(buffer));
	printf("byteCount=	[%d]\n",byteCount);
}
void sigHandler2(int sig){
	printf("take a signal [%d]\n",sig);
	close(fd);
	exit(0);
}
void sigHandler3(int sig){
	printf("take a signal [%d]\n",sig);
	fd=open("./log.txt",O_RDWR|O_CREAT|O_TRUNC,\
					 S_IRWXU|S_IWGRP|S_IRUSR|S_IRGRP|S_IROTH);

}
int main(void){
	signal(SIGUSR1,sigHandler3);
	signal(SIGQUIT,sigHandler);
	signal(SIGINT,sigHandler);
	signal(SIGUSR2,sigHandler2);
	// fd=open("./log.txt",O_RDWR|O_CREAT|O_TRUNC,\
					 S_IRWXU|S_IWGRP|S_IRUSR|S_IRGRP|S_IROTH);

	while(1){
	
			pause();
			
	}
	
	//close(fd);
	return 0;
}
