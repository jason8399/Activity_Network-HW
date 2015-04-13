//main.c

#include <stdio.h>
#include <stdlib.h>
#include "Activity_Network.h"

int main(int argc, const char *argv[])
{
	int i, k, l, dur, nodeNum, edgeNum;
	int earliest[MAX_VERTICES] = {0}, latest[MAX_VERTICES] = {0}, order[MAX_VERTICES] = {0}, path[MAX_PATH] = {0};
	hdnodes graph[MAX_VERTICES] = {0};

	scanf("%d %d", &nodeNum, &edgeNum);
	for(i = 0; i < edgeNum; i++){
		scanf("%d %d %d", &k, &l, &dur);
		insertNode(graph, k, l, dur);
	}
	topSort(graph, nodeNum, earliest, order);
	checkUnreachable(earliest, nodeNum);
	latestTime(graph, nodeNum, latest, order, earliest);
	printCritical(graph, nodeNum, earliest, latest);
	traversalCritical(graph, nodeNum - 1, 0, path, 0, earliest, latest);
	printf("Critical Long: %d\n", earliest[nodeNum - 1]);
	return 0;
}
