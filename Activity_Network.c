//Activity_Network.c

#include <stdio.h>
#include <stdlib.h>
#include "Activity_Network.h"

void topSort(hdnodes graph[], int n, int earliest[], int order[]){
	int i, j, k, top;
	nodePointer ptr;
	/*create a stack of vertices with no predecessors*/
	top = -1;
	for(i = 0; i < n; i++){
		if(!graph[i].count){
			graph[i].count = top;
			top = i;
		}
	}
	for(i = 0; i < n; i++){
		if(top == -1){
			fprintf(stderr, "\nNetwork has acycle. Sort terminated.\n");
			exit(EXIT_FAILURE);
		}
		else{
			j = order[i] = top; /*unstack a vertex*/
			top = graph[top].count;
			//printf("v%d", j);
			for(ptr = graph[j].link; ptr; ptr = ptr->link){
				/*decrease the count of the successor vertices of j*/
				k = ptr->vertex;
				if(earliest[k] < earliest[j] + ptr->dur){
					earliest[k] = earliest[j] + ptr->dur;
				}
				graph[k].count--;
				if(!graph[k].count){
					/*add vertex k to the stack*/
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}

void latestTime(int latest[], int n, int order[]){

}
