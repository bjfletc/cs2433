// Brandon J. Fletcher
// CS 2433: C/C++ Programming
// 2016 Fall Semester
// Assignment: program5
// Due date: September 25, 2016
// Date submitted: *
// Instructor: Richard Churchill

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wnode
{
    char aword[16];
    struct wnode *last;
    struct wnode *next;
} wnode;

int
main(void)
{
    /*
     * declare variables to be used within the program
     */
    wnode listNodes[100];
    wnode *thisOne;
    wnode *thatOne;
    wnode *newNode;
    wnode *freeNodes;
    wnode *headNode;
    
    // create the HEADNODE
    headNode = (wnode *) listNodes;
    headNode->last = (wnode *) NULL;
    headNode->next = (wnode *) NULL;
    strcpy(headNode->aword, "HEADNODE");
    
    return 0;
} // end of main
