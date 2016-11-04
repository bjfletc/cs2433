#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wnode {
    char aword[16];
    struct wnode *last;
    struct wnode *next;
} wnode;

int main(int argc, char *argv[]) {

    int i;

    wnode listNodes[100];
    wnode *thisOne;
    wnode *thatOne;
    wnode *newNode;
    wnode *freeNodes;
    wnode *headNode;

    headNode = (wnode *) listNodes;
    headNode->next = (wnode *) NULL;
    headNode->last = (wnode *) NULL;
    strcpy(headNode->aword, "HEADNODE");

    thisOne = ((wnode *) listNodes) + 1;
    freeNodes = thisOne;
    for (i = 1; i < 99; i++) {
        thisOne->next = thisOne + 1;
        thisOne->last = (wnode *) NULL;
        sprintf(thisOne->aword, "%d", i);
        thisOne = thisOne + 1;
    }
    thisOne->next = (wnode *) NULL;
    thisOne->last = (wnode *) NULL;
    strcpy(thisOne->aword, "freeTail");

    thisOne = freeNodes;
    while (thisOne != (wnode *) NULL) {
        printf("%s ", thisOne->aword);
        thisOne = thisOne->next;
    }
    printf("\n");

    return 0;
}
