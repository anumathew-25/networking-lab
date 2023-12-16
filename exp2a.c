#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int num1,num2,i,pid;
	pid=getpid();
	printf("Process id of program 1:%d\n",pid);
	printf("Enter two numbers:\n");
	scanf("%d%d",&num1,&num2);
	printf("Sum:%d\n",num1+num2);
	char *args[]={"4","Hello","World",NULL};
	execv("./pg2",args);
	return 0;
}	
