#define MAX_NAME_LENGTH 32

typedef struct Song {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
} Song;

typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;

// Insert 
int enqueue(PQueueNode **pqueue, int priority, void *data);

// Delete
void *dequeue(PQueueNode  **pqueue);

// Find
void *peek(PQueueNode *pqueue);

void printQueue(PQueueNode *pqueue, void (printFunction) (void*));

int getMinPriority(PQueueNode *pqueue);

int queueLength(PQueueNode *pqueue);

void printSong(void *data);