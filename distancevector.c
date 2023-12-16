#include<stdio.h>
#include<limits.h>
#define MAX_NODES 10
struct nodes{
	int dist[MAX_NODES];
	int through[MAX_NODES];
};
int main(){
	int n,i,j,k,matrix[MAX_NODES][MAX_NODES],distanceVector[MAX_NODES][MAX_NODES],through[MAX_NODES][MAX_NODES];
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	struct nodes node[n];
	printf("ENter the distance between each node(if there is no collection then -1):\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				printf("Distanvce between %d and %d:",i,j);
				scanf("%d",&node[i].dist[j]);
				if(node[i].dist[j]!=-1){
					node[i].through[j]=j;
				}
				else{
					node[i].through[j]=-1;
				}
			}		
			else{
				node[i].dist[j]=0;
				node[i].through[j]=-1;
			}
		}
	}
	printf("\nInitial Distance table:\n");
	printf("\t");
	for(i=0;i<n;i++){
		printf("%d\t",i);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("Node %d:\t",i);
		for(j=0;j<n;j++){
			printf("%d\t",node[i].dist[j]);
			node[i].through[j]=j;
		}
		printf("\n");
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(node[i].dist[k]!=-1 &&node[k].dist[j]!=-1){
					int newDistance=node[i].dist[k]+node[k].dist[j];
					if(newDistance<node[i].dist[j] || node[i].dist[j]==-1){
						node[i].dist[j]=newDistance;
						node[i].through[j]=node[i].through[k];
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		printf("\nDistance vector table for node %d:\n",i);
		printf("Node\tDistance\tThrough\n");
		for(j=0;j<n;j++){
			printf("%d\t",j);
			printf("\t%d\t",node[i].dist[j]);
			printf("\t%d\n",node[i].through[j]);
		}
	}
	return 0;
}								
								
						

