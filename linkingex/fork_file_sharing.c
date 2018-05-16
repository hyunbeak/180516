#include<stdio.h>
#include<fcntl.h>
#include<sys/wait.h>
#include"tlpi_hdr.h"
#include"error_functions.h"
//void errExit(const char *format, ...);
int main(int argc,char *argv[]){
	int fd,flags;
	char template[] = "\tmp\testXXXXXX";//함수쪽에서 정하게 하기 위해서 xxxxxx를 넣음
	setbuf(stdout,NULL);//버퍼 사용하지않겟다printf  의

	fd=mkstemp(template);//파일을 하나 연다. 
	if(fd==-1)
			errExit("mkstemp");
	printf("File offset before fork(): %lld\n",(long long)lseek(fd,0,SEEK_CUR));

	flags= fcntl(fd,F_GETFL);//fcntl 파일의 속성을 설정, F_GETFL 플래그를 가져옴
	if(flags == -1)
			errExit("fcntl - F_GETFL");
	printf("O_APPEND flag befor fork() is: %s\n",(flags & O_APPEND)?"on":"off");

	switch(fork()){
			case -1:
					errExit("fork");
			case 0:
					if(lseek(fd,1000,SEEK_SET)==-1)
							errExit("lseek");

					flags = fcntl(fd,F_GETFL);
					if(flags == -1)
							errExit("fcntl - F_GETFL");
					flags |= O_APPEND;
					if(fcntl(fd,F_SETFL,flags)==-1)
							errExit(EXIT_SUCCESS);
					exit(EXIT_SUCCESS);
			default:
					if(wait(NULL)==-1)
							errExit("wait");
					printf("Child has exited\n");

					printf("File offset in parent : %lld\n",(long long) lseek(fd,0,SEEK_CUR));
					flags = fcntl(fd,F_GETFL);
					if(flags==-1)
							errExit("fcntl - F_GETFL");
					printf("O_APPEND flag in parent is : %s\n",(flags & O_APPEND)?"on":"off");
					exit(EXIT_SUCCESS);

	}
}
//void errExit(const char *format, ...){
//va_list argList;
//va_start(argList,format);
//outputError(TRUE,errno,TRUE,format,argList);
//va_end(argList);
//terminate(TRUE);
//}
