#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pqueue.tscott5.h"

int enqueue(PQueueNode **pqueue, int priority, void *data) {

    if (pqueue == NULL) {
        return 1;
    }

    else {

        PQueueNode *curr = *pqueue;
        PQueueNode *prev = NULL;

        PQueueNode *newElement = (PQueueNode *) malloc(sizeof(PQueueNode));
        newElement->priority = priority;
        newElement->data = data;

        if (curr == NULL) {
            *pqueue = newElement;
        }

        else {

            while (curr != NULL && priority >= curr->priority) {
                prev = curr;
                curr = curr->next;
            }

            newElement->next = curr;

            if (prev != NULL) {
                prev->next = newElement;
            }
            
            else {
                *pqueue = newElement;
            }
        }
    }
    return 0;
}

void *dequeue(PQueueNode **pqueue) {
    
    PQueueNode *curr = *pqueue;
    PQueueNode *prev = NULL;

    if (curr == NULL) {
        return NULL;
    }

    else {
        if (prev != NULL) {
            prev->next = curr->next;
        }
        else {
            *pqueue = curr->next;
        }

        //free(curr);
        return curr->data;
    }
}

void *peek(PQueueNode *pqueue) {

    PQueueNode *curr = pqueue;

    if (curr != NULL) {
        return curr->data;
    }

    else {
        return NULL;
    }
}

void printQueue(PQueueNode *pqueue, void (printFunction) (void*)){

    PQueueNode *qnode;
    qnode = pqueue;

    while (qnode != NULL) {
        printf("priority = %d data = ", qnode->priority);
        printFunction(qnode->data);
        qnode = qnode->next;
    }

}

int getMinPriority(PQueueNode *pqueue) {

    PQueueNode *qnode;
    qnode = pqueue;
    
    if (qnode == NULL) {
        return -1;
    }

    else {
        return qnode->priority;
    }
}

int queueLength(PQueueNode *pqueue){

    PQueueNode *qnode;
    qnode = pqueue;

    int length = 0;

    if (qnode == NULL) {
        return 0;
    }

    while (qnode != NULL) {
        length += 1;
        qnode = qnode->next;
    }

    return length;
}

void printSong(void *data) {

    Song *song; 
    song = (Song *) data;

    printf("\"%s\" (%s)\n", song->title, song->artist);
}