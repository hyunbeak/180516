#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
pid_t pid;
void sigHandler(int sig){
	static int count =1;
	printf("activate sigHandler.count value is :%d\n",count);
	
	if(count==5){
			(void)signal(SIGINT,SIG_DFL);
			kill(pid,SIGINT);
			exit(0);
			//kill(pid,SIGINT);
	}
	count++;
}

int main(void){
	
	//pid_t pid;
	int fd,byteCount;
	char buffer[10];
	signal(SIGINT,sigHandler);
	
	pause();
	 fd=open("./readPID.txt",O_RDONLY,\
					 S_IRWXU|S_IWGRP|S_IRUSR|S_IRGRP|S_IROTH);

	 byteCount=read(fd,buffer,10);
	 printf("%s",buffer);
	  pid=atoi(buffer);
	  close(fd);

	while(1){
	//printf("1");
	kill(pid,SIGINT);
	pause();
	}
	return 0;
}
