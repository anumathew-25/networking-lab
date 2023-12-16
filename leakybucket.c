#include<stdio.h>
#include<unistd.h>
int main(){
	int buffS,buffSize,no,i,bucket[50],temp=0,count=0,packet[50],rate,time,dataSent=0;
	printf("Enter the buffer size:");
	scanf("%d",&buffSize);
	buffS=buffSize;
	printf("Enter the number of packets:");
	scanf("%d",&no);
	for(i=0;i<no;i++){
		printf("Size of the packet [%d]:",i);
		scanf("%d",&temp);
		if(temp>buffS){
			printf("Packet size is greater than buffer space\n");
		}
		else{
			bucket[count]=i;
			buffS-=temp;
			packet[count]=temp;
			count++;
		}
	}
	printf("\nEnter the rate of data flow:");
	scanf("%d",&rate);
	printf("\nTime interval of data flow:");
	scanf("%d",&time);
	for(i=0;i<count;i++){
		while(packet[i]>0){
			sleep(time);
			packet[i]-=rate;
			dataSent++;
		}
		printf("Packet[%d] completed in %d send\n",bucket[i],dataSent);
	}
}					
