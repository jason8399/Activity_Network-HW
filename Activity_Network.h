//Activity_Network.h

#define MAX_VERTICES 20
#define MAX_PATH 20

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


void topSort(hdnodes graph[], int n, int earliest[], int order[]);
void latestTime(hdnodes graph[], int n, int latest[], int order[], int earliest[]);
void printCritical(hdnodes graph[], int n, int earliest[], int latest[]);
void insertNode(hdnodes graph[], int k, int l, int dur);
void traversalCritical(hdnodes graph[], int end, int now, int path[], int pathLong,int earliest[], int latest[]);
void checkUnreachable(int earliest[], int n);
