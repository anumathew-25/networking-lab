#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
int pid,ppid,i,num1,num2;
if(fork()==0){
pid=getpid();
ppid=getppid();
printf("Child process starts here\n");
printf("Process id of the child prcess:%d\n",pid);
printf("Process id of the parent from child process: %d\n",ppid);
printf("Enter any two numbers:\n");
scanf("%d%d",&num1,&num2);
printf("Sum:%d\n",num1+num2);
printf("Child process ends\n");
}
else{
pid=getpid();
printf("Parent process starts here\n");
printf("process id of the parent process:%d\n",pid);
wait(NULL);
printf("Ten numbers are:\n");
for(i=1;i<=10;i++){
printf("%d\n",i);
}
printf("Parent process ends here\n");
}
return 0;
}
