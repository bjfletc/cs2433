//=============================================================================
// This code is an exmaple of how to intialize the nodes that will be used in
// program 5, along with a piece of code that performs node deletion.  This
// sample should help in understanding how to use pointers.  It does not show
// how to convert the program as a whole to use functions for the operations
// specified in the assignment.  That will depend on how you wrote program 4.

// the libraries used ...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the typedef struct for the nodes ...

typedef struct wnode {
    char aword[16];         // for storing a word, up to 15 chars in length
    struct wnode *last;     // link to the previous node in in-order traversal
    struct wnode *next;     // link to the next in in-order traversal
} wnode;

//-----------------------------------------------------------------------------
// int main(int argc, char *argv[])
//     reads in strings, one at a time, from stdin, and prints the word list
// in-order & reverse order then halts on reading "!stop"; deletes any word
// prefixed by a tilde ('~'); inserts any other printable string as a "word".
//

int main(int argc, char *argv[]) {

    int i;                  // used as a counter
    char inStr[128];        // to read strings into

    wnode listNodes[100];   // allocate the nodes
    wnode *thisOne;         // for use in searching the doubly linked list
    wnode *newNode;         // for inserting a node with a new word
    wnode *freeNodes;       // pointer to the first node of the free node list
    wnode *headNode;        // pointer to the head-node

    // this initializes the head-node to point to itself, so we can use it

    headNode = listNodes;
    headNode->next = headNode;
    headNode->last = headNode;
    strcpy(headNode->aword, "HEADNODE");

    // set to loop through initializing the free node list

    thisOne = listNodes + 1;
    freeNodes = thisOne;

    // loop through the other nodes to construct the free node list.
    // this is different from past intializations, as we deal with the last
    // node (99) as all others, but then over-write the .next field with the 
    // null pointer needed to indicate end-of-list.

    for (i = 1; i <= 99; i++) {
        thisOne->aword[0] = '\0';
        thisOne->next = thisOne + 1;
        thisOne->last = (wnode *) NULL;
        thisOne = thisOne + 1;
    }
    thisOne->next = (wnode *) NULL;

    // this is essentially the same infinite loop as for program 4, but with
    // the deletion code re-written to use pointers, and the insertion section
    // removed so you have to write it.

    while(-1) {
    	// as before, get the input string

        scanf("%s", inStr);

        // this is the same test we had before for stopping
        if (strcmp(inStr, "!stop") == 0) {
            break;
        }

        // here we again check for a delete command, but we are now using
        // pointers to handle list linkage

        if (*inStr == '~') {
        	// this uses the "trick" discussed in class for truncating a string
        	// to a desired length (or shorter) without having to determine the
        	// actual length of the string.  remember, standard strings in C
        	// are terminated with a null-character (a value of 0), which can
        	// be written as '\0'.  In this case, since we have to skip the 
        	// tilde, we place this null-character one position further along
        	// the string than we would if we were doing an insertion, since we

            inStr[16] = '\0';

            // again, the same as worked for program 4, but now using pointers

            thisOne = headNode->next;
            while ((thisOne != headNode) && (strcmp((inStr + 1), thisOne->aword) != 0)) {
                thisOne = thisOne->next;
            }

            // test for having failed to find the word/node to delete, handling
            // both found and not found as required.  in the following, notice
            // the pointer-to-a-pointer-to-data usage.  this is much clearer
            // than trying to do the same with indices.

            if (thisOne != headNode) {
                thisOne->last->next = thisOne->next;    // links the predecessor
                                                        // to the successor
                thisOne->next->last = thisOne->last;    // links the successor
                                                        // to the predecessor
                thisOne->next = freeNodes;              // now link the node
                freeNodes = thisOne;                    // just freed into the
                                                        // free node list
            }
            else {
                printf("Word not found.\n");    // can't delete what you did
                                                // not find!
            }
        }
        else {
            // handle insertion here
        }
    }

    // and we get to writing the list of words in both orders, but using
    // pointers ...

    thisOne = headNode->next;
    while (thisOne != headNode) {
        printf("%s ", thisOne->aword);
        thisOne = thisOne->next;
    }
    printf("\n\n");
    thisOne = headNode->last;
    while (thisOne != headNode) {
        printf("%s ", thisOne->aword);
        thisOne = thisOne->last;
    }
    printf("\n");

    return 0;
}
