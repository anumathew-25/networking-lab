#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	int pid,i;
	pid=getpid();
	printf("Process id of program 2:%d\n",pid);
	for(i=0;i<argc;i++){
		printf("Argument %d : %s\n",i,argv[i]);
	}
	return 0;
}		
