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

void latestTime(hdnodes graph[], int n, int latest[], int order[], int earliest[]){
	int count = n - 1, i, j, k;
	nodePointer ptr;
	latest[count] = earliest[count];
	for(i = count - 1;i >= 0; i--){
		j = order[i];
		for(ptr = graph[j].link; ptr; ptr = ptr->link){
			k = ptr->vertex;
			if(!latest[j] || latest[j] > latest[k] - ptr->dur){
				latest[j] = latest[k] - ptr->dur;
			}
		}
	}
}

void printCritical(hdnodes graph[], int n, int earliest[], int latest[]){
	int i, j, e, l, count = 0;
	nodePointer ptr;
	printf("activity\te\tl\tl-e\tcritical\n");
	for(i = 0; i < n; i++){
		for(ptr = graph[i].link; ptr; ptr = ptr->link){
			j = ptr->vertex;
			e = earliest[i];
			l = latest[j] - ptr->dur;
			printf("a%-3d\t\t%-4d\t%-4d\t%-4d\t%s\n", count++, e, l, l - e, !(l - e) ? "YES": "NO");
		}
	}
}

void insertNode(hdnodes graph[], int k, int l, int dur){
	nodePointer ptr, newNode;
	if(graph[k].link == NULL){
		graph[k].link = malloc(sizeof(node));
		graph[k].link->vertex = l;
		graph[k].link->dur = dur;
		graph[k].link->link = NULL;
	}else{
		for(ptr = graph[k].link; ptr; ptr = ptr->link){
			if(!(ptr->link)){
				newNode = malloc(sizeof(node));
				newNode->vertex = l;
				newNode->dur = dur;
				newNode->link = NULL;
				ptr->link = newNode;
				break;
			}
		}
	}
	graph[l].count++;
}

void traversalCritical(hdnodes graph[], int end, int now, int path[], int pathLong,int earliest[], int latest[]){
	int i, j, e, l;
	nodePointer ptr;
	if(now == end){
		for(i = 0; i < pathLong; i++)
			printf("%d ", path[i]);
		printf("%d\n", now);
		return;
	}
	else{
		path[pathLong] = now;
		for(ptr = graph[now].link; ptr; ptr = ptr->link){
			j = ptr->vertex;
			e = earliest[now];
			l = latest[j] - ptr->dur;
			if(!(l - e)){
				traversalCritical(graph, end, j, path, pathLong + 1, earliest, latest);
			}
		}
	}
}

void checkUnreachable(int earliest[], int n){
	int i;
	for(i = 1; i < n; i++){
		if(!earliest[i]){
			fprintf(stderr, "\nNetwork has Unreacheable. Terminated.\n");
			exit(EXIT_FAILURE);
		}
	}
}
