//main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Activity_Network.h"

int main(int argc, const char *argv[])
{
	int i, k, l, dur;
	int earliest[MAX_VERTICES], latest[MAX_VERTICES], order[MAX_VERTICES];
	nodePointer ptr;
	memset(latest, 999, sizeof(latest));
	while(1){
		scanf("%d %d %d", &k, &l, &dur);
		if(!k && !l && !dur) break;
		insertNode(graph, k, l, dur);
	}
	topSort(graph, MAX_VERTICES, earliest, order);
	latestTime(graph, MAX_VERTICES, latest, order, earliest);
	printCritical(graph, MAX_VERTICES, earliest, latest);

	return 0;
}
