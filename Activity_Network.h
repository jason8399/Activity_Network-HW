//Activity_Network.h

#define MAX_VERTICES 9

typedef struct node *nodePointer;

struct node {
	int vertex;
	int dur;
	nodePointer link;
};
typedef struct node node;

typedef struct {
	int count;
	nodePointer link;
} hdnodes;

hdnodes graph[MAX_VERTICES];

void topSort(hdnodes graph[], int n, int earliest[], int order[]);
void latestTime(int latest[], int n, int order[]);
