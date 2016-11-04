// the following is without much of the "boiler plate" code, such
// as variable declarations, but shows the overall structure of
// the main() functions execution.  You will need to add that
// material, and any necessary corrections to the following code
// to match your code, but the following is essentially correct.

// this intializes the head-node

strcpy(listNodes[0].aword, "HEADNODE");
listNodes[0].next = 0;
listNodes[0].last = 0;

// this initialize the non-HEADNODE nodes as the list of free nodes

for (int i = 1; i < 99; i++) {
    listNodes[i].aword[0] = 0;
    listNodes[i].last = 0;
    listNodes[i].next = i+1;
}

listNodes[99].aword[0] = 0;
listNodes[99].next = -1;
listNodes[99].last = 0;
freeNodes = 1;

// this is the basic logic of the loop that reads commands from
// stdin and inserts or deletes words from the doubly linked list,
// or halts that processing.

while(-1) {
    scanf("%s", inputstr);
    if (strcmp(inputsrt, "!stop") == 0) break;
    if (inputsrt[0] == '~') {
        // handle deletion
    }
    else {
        // handle insertion
    }
}

// the following prints the list of words in the doubly linked
// list, with at least one blank line separating the two orderings.

thisOne = listNodes[0].next;
while (thisOne != 0) {
    printf("%s ", listNodes[thisOne].aword);
    thisOne = listNodes[thisOne].next;          // moves thisOne to next node
}

printf("\n\n");

thisOne = listNodes[0].last;
while (thisOne != 0) {
    printf("%s ", listNodes[thisOne].aword);
    thisOne = listNodes[thisOne].last;
}

//------------------------------------------------------------
// the assignment for program 5 uses the same basic structure,
// but changes the use of ints to pointers for linking the two
// lists together.

