//Activity_Network.h

#define MAX_VERTICES 8

typedef struct node *nodePointer;
typedef struct node {
	int vertex;
	int dur;
	nodePointer link;
};
typedef struct {
	int count;
	nodePointer link;
} hdnodes;

hdnodes graph[MAX_VERTICES];
