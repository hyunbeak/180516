#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
void sigHandler(int sig){
	static int count =1;

	printf("activate Handler . count value is :%d\n",count);
	
	if(count==5){
			(void)signal(SIGINT,SIG_DFL);
			//kill(pid,SIGINT);
			exit(0);
	}
	count++;
}
int main(int argc,char* argv[]){
	pid_t pid;	
	int fd,byteCount;
	char buffer[10];
	//pid_t pid;
	//signal(SIGINT,sigHandler);
	
	pid=getpid();
	sprintf(buffer,"%d",pid);
	fd=open("./readPID.txt",O_RDWR|O_CREAT|O_TRUNC,\
					S_IRWXU|S_IWGRP|S_IRUSR|S_IRGRP|S_IROTH);
	byteCount=write(fd,buffer,strlen(buffer));
	close(fd);
	pid=atoi(argv[1]);
	signal(SIGINT,sigHandler);
	//kill(pid,SIGINT);
		while(1){
						
				//sig=atoi(argv[1]);
				//kill(argv[1],)
		//		printf("%d",pid);

						kill(pid,SIGINT);
						pause();
						//kill(pid,SIGINT);
		}
		
	return 0;
}
