/* 
Please note that the instructions for these assignments state that you are 
to insert each word to be inserted into the sorted doubly linked list.  That 
means that after each insertion the list remains sorted, else it may not be 
when you insert the next word.  This type of sort is an insertion sort.

As for the declaration of the array of nodes, once you have declared the array 
and initialized the head-node and the free node list, you will not be concerned 
with the operations on the array as a whole, only on the two lists.  Printing 
the doubly linked list means traversing the list, not iterating through the 
array.  Traversal of the doubly linked list in both in-order and reverse-order 
directions is shown in the code sample emailed earlier.  Apart from the use of 
indexing to access individual nodes, you never treat the nodes as part of an 
array of nodes after initialization.

After initialization (shown in the emailed code sample), all operations are on 
the two lists.  To insert a word, you remove a node from the free node list, 
copy up to 15 characters from the input string read from stdin to the aword 
field of the node, then search the doubly linked list for the proper location 
to place the node so that the words in the nodes are in order as defined by the 
strcmp() function.

(Note that the upper- and lower-case letters are not treated as equal, so all 
words that start with lower-case letters will come before all words that start 
with upper-case letters.  Likewise, for two strings a and b, if they are ident-
ical in their first n characters, but differ in case in the n+1 character, the 
one with the lower-case letter comes before the other.)

Deletion of a word from the doubly linked list is specifically stated to in-
clude deletion of the node.  When reading stdin yields a string starting with 
a tilde ('~'), you must use the sub-string that follows the tilde for searching 
the doubly linked list for the word, and thus the node to be deleted.  Deleting 
the node deletes the word from the list.  Again, there is a limit to the length 
of the word to be deleted, just as there was for the insertion of words, since 
the aword field of the wnodes typedef/struct contains only 16 characters.  
Strings in C are "null terminated", which means the string of non-null char-
acters contained can be no longer than 15 chars long.  So, both reading in 
words requires that you truncate strings properly, remembering that you must 
deal with words to be inserted differently from those to be deleted, due to the 
presence of the tilde in the latter case.

Nodes deleted from the doubly linked list are to be placed back on the free 
node list.  You do not need to do anything to the aword and last fields of 
nodes being deleted from the doubly linked list and returned to the free node 
list, since we don't care what is in those fields when the node is in the free 
node list, and we will over-write the contents of those fields when we are in-
serting it into the doubly linked list.

Placing a node being deleted from the doubly linked list onto the free node 
list is very simple.  Here is code that does this, assuming thisOne is the 
index of the node, in the array listNodes, being placed on the free node list, 
and freeNodes contains the index of the first node in the free node list. */
*/

    listNodes[thisOne].next = freeNodes;
    freeNodes = thisOne;

/* 
Deletion of a node from the doubly linked list is also simple, as shown in the 
following code sample, where thisOne is the index of the node being deleted.
*/

    listNodes[listNodes[thisOne].next].last = listNodes[thisOne].last;
    listNodes[listNodes[thisOne].last].next = listNodes[thisOne].next;

/*
If we assume we have two ints, left and right, declared elsewhere, the follow-
ing is somewhat easier to understand.
*/

    right = listNodes[thisOne].next;
    left = listNodes[thisOne].last;
    listNodes[right].last = left;
    listNodes[left].next = right;

/*
Insertion of a node, once you have found where you should insert it, is only 
slightly more complex.  If thisOne is the index of the node that will follow 
the inserted node after insertion, and newNode is the index of the node to be 
inserted, the following inserts the node.
*/

    listNodes[newNode].last = listNodes[thisOne].last;
    listNodes[newNode].next = thisOne;
    listNodes[thisOne].last = newNode;
    listNodes[listNodes[newNode].last].next = newNode;

/*
We can make this process a little clearer if we assume we have an int (thatOne) 
declared earlier, and can use it here.
*/

    thatOne = listNodes[thisOne].last;
    listNodes[newNode].next = thisOne;
    listNodes[newNode].last = thatOne;
    listNodes[thatOne].next = newNode;
    listNodes[thisOne].last = newNode;

/*
As for searching the doubly linked list for a word to delete, or where to in-
sert a node with a new word, read the documentation for strcmp() (or strncmp()) 
carefully, and remember that there are three different results possible.  A 
negative returned by a call to strcmp(str1, str2) means that str1 should come 
before str2 in sorted order, while a positive returned means that str1 should 
come after str2 in sorted order, and a zero returned means the strings are the 
same.

The following code searches a doubly linked list for node containing the string
at seekStr, where seekStr is a pointer to a character array.  Note that the 
loop must have a test for not finding the word, since we cannot guarantee that 
we will find that word in the list.  We can test for that by simply checking 
whether thisOne contains the ID of the head-node.
*/

    thisOne = listNodes[0].next;
    while ((thisOne != 0) && (strcmp(seekStr, listNodes[thisOne].aword == 0))) {
        thisOne = listNodes[thisOne].next;
    }

/*
The loop to look for a place to insert a word/node into the doubly linked list 
will actually be very similar, with only the relational operator ("==") in the 
second clause of the loop test changed, so that the search will stop either 
when the search returns to the head-node or the proper place is found in the 
doubly linked list for us to insert the new word/node.  READ THE DOCUMENTATION 
for strcmp() and strncmp() so you can what test to use.

Do not forget that the tilde that indicates a word (and its node) is to be 
deleted means that you must compare the up to 15 chars that follow the tilde, 
whereas when you are inserting a new word/node you have no tilde, and so can 
start the string comparisons at the first char (index 0), and for up to 15 
chars.  If you have trouble with how to handle the difference, or truncating 
the strings of chars from stdin, let me know and we can talk you through the
problem.
*/