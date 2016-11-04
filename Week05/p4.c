// Brandon J. Fletcher
// CS 2433: C/C++ Programming
// 2016 Fall Semester
// Assignment: program2
// Due date: September 17, 2016
// Date submitted: September 17, 2016
// Instructor: Richard Churchill

#include <stdio.h>
#include <string.h>

typedef struct wnode_struct {
	char aword[16];
	int last;
	int next;
} wnode;

int main(void)
{

	// Create Double <-> Linked List
	wnode listNodes[100];

	// Creat HEADNODE
	strcpy(listNodes[0].aword, "HEADNODE"); listNodes[0].last = -1; listNodes[0].next = 1; // done on single line to conserve room

	char currentUserInput[16];
	char stringToEndProgram[5] = "!stop";
    char firstCharacterOfUserInput; // i.e. used to find "~" case
    int lengthOfCurrentUserInput;
    char wordToDelete[15];
	int freeNodes = 1;
	int a = freeNodes; // index of next node to be unlinked
    int endOfList = (a - 1);
    int stringBeforeCurrentUserInputInAlphabeticalOrder; // certain to be the node before currentUserInput
    int thisStringShouldGoFirst = 0; // this means that our do{}while() did not find a node before currentUserInput & currentUserInput should then go first
    
	while(1)
	{
		printf("Enter String For Insertion || Deletion\n");
		scanf("%16s", currentUserInput);
        firstCharacterOfUserInput = currentUserInput[0];
        
		if (strcmp(stringToEndProgram, currentUserInput) == 0)
		{
            int nodeToPrint = 0;
            do
            {
                if (nodeToPrint == 0)
                {
                    printf("%s <-> ", listNodes[0].aword);
                    printf("%s <-> ", listNodes[listNodes[0].next].aword);
                }
                else if (listNodes[nodeToPrint].next != 0)
                {
                    printf("%s <-> ", listNodes[listNodes[nodeToPrint].next].aword);
                }
                else
                {
                    printf("%s", listNodes[listNodes[nodeToPrint].next].aword);
                    break;
                }
                nodeToPrint = listNodes[nodeToPrint].next;
            }
            while (nodeToPrint != a);

            printf("\n\n");

            //printf("%d = listNodes[0].last", listNodes[0].last);
            // pirntf("%d is the lastNode\n", lastNode);
            
            printf("HEADNODE <-> ");
            int nodeToPrintInReverse = listNodes[0].last;
            do
            {
                if (listNodes[nodeToPrintInReverse].last != 0)
                {
                    printf("%s <->", listNodes[nodeToPrintInReverse].aword);
                }
                else
                {
                    printf("%s", listNodes[nodeToPrintInReverse].aword);
                    break;
                }
                nodeToPrintInReverse = listNodes[nodeToPrintInReverse].last;
            }
            while (nodeToPrintInReverse != a);
            printf("<-> HEADNODE\n");
            
            
            printf("\n--END PROGRAM p4.c--\n");
			break;
		}
        /*
         * if this point has been reached then firstCharacterOfUserInput must == "~"
         * meaning that we need need to delete the word that follows it
         */
        else if (firstCharacterOfUserInput == '~')
        {
            
            printf("We Need to Delete: %s\n", wordToDelete);
            
            int checkForWordToDelete = 0;
            int wordToDeleteMemoryLocation = 0;
            do
            {
                if (strcmp(listNodes[listNodes[checkForWordToDelete].next].aword, wordToDelete) == 0)
                {
                    wordToDeleteMemoryLocation = (checkForWordToDelete + 1);
                    if (wordToDeleteMemoryLocation != 0)
                    {
                        // we know where to go at this point
                        break;
                    }
                }
                checkForWordToDelete = listNodes[checkForWordToDelete].next;
            }
            while (listNodes[checkForWordToDelete].next != 0);
            
            // swap memory points
            if (listNodes[wordToDeleteMemoryLocation].next == 0)
            {
                listNodes[listNodes[wordToDeleteMemoryLocation].last].next = 0;
                listNodes[a].next = 0;
            }
            else if (listNodes[wordToDeleteMemoryLocation].last == 0) // new head of list
            {
                /*
                 *  • HEADNODE [-1, 1] <-> Brandon [0, 2] <-> Creston [1, endOfList]
                 *  • ~Brandon:
                 *  •           HEADNODE [-1, 2] <-> Creston [0, endOfList]
                 *  • Thus; HEADNODEs "next" should point to wordToDelete's .next
                 *  • & (wordToDelete.next).last should point to wordToDelete.last
                 */
                listNodes[listNodes[wordToDeleteMemoryLocation].next].last = 0;
                listNodes[0].next = listNodes[wordToDeleteMemoryLocation].next;
            }
            else
            {
                // we've reached a point where there is a node on both sides of wordToDelete
                listNodes[listNodes[wordToDeleteMemoryLocation].last].next = listNodes[wordToDeleteMemoryLocation].next;
                listNodes[listNodes[wordToDeleteMemoryLocation].next].last = listNodes[wordToDeleteMemoryLocation].last;
                
            }
            
            
            // set wordToDeleteMemoryLocation back to 0 for if(check)
            wordToDeleteMemoryLocation = 0;
        }
        
		else
		{
			if (a == 1) // handles if there's just one input
			{
				strcpy(listNodes[a].aword, currentUserInput);
				listNodes[1].last = 0;
				listNodes[1].next = endOfList;

                listNodes[0].last = 1;
                
                
			}
            else if (a == 2)
            {
                if (strcmp(listNodes[1].aword, currentUserInput) < 0)
                {
                    strcpy(listNodes[2].aword, currentUserInput);
                    listNodes[2].last = 1;
                    listNodes[2].next = endOfList;
                    listNodes[1].next = 2;

                    listNodes[0].last = 2;
                }
                else if (strcmp(listNodes[1].aword, currentUserInput) > 0)
                {
                    
                    strcpy(listNodes[2].aword, currentUserInput);
                    listNodes[2].last = 0;
                    listNodes[2].next = 1;
                    
                    listNodes[1].last = 2;
                    listNodes[1].next = endOfList;
                    listNodes[0].next = 2;
                }
            }
            else
            {
                strcpy(listNodes[a].aword, currentUserInput);
                
                int check = 0;
                do
                {
                    if (strcmp(listNodes[listNodes[check].next].aword, currentUserInput) < 0)
                    {
                        stringBeforeCurrentUserInputInAlphabeticalOrder = listNodes[check].next;
                    }
                    else if (strcmp(listNodes[1].aword, currentUserInput) > 0)
                    {
                        thisStringShouldGoFirst = 10;
                        break;
                    }
                    check = listNodes[check].next;
                }
                while (listNodes[check].next != 0);
                if (listNodes[stringBeforeCurrentUserInputInAlphabeticalOrder].next == 0)
                {
                    listNodes[a].last = stringBeforeCurrentUserInputInAlphabeticalOrder;
                    listNodes[a].next = 0;

                    // DEBUGGER
                    printf("--DEBUGGER--\n listNodes[a].last = %d\n", listNodes[a].last);
                    
                    listNodes[0].last = a; //should update

                    printf("--DEBUGGER2--\n listNodes[0].last = %d\n", listNodes[0].last);
                    listNodes[stringBeforeCurrentUserInputInAlphabeticalOrder].next = a;
                }
                else if (thisStringShouldGoFirst == 10) // between two nodes
                {
                    listNodes[a].last = 0;
                    listNodes[a].next = listNodes[0].next;
                    listNodes[listNodes[0].next].last = a;
                    listNodes[0].next = a;
                }
                else
                {
                    listNodes[a].last = stringBeforeCurrentUserInputInAlphabeticalOrder;
                    listNodes[a].next = listNodes[stringBeforeCurrentUserInputInAlphabeticalOrder].next;
                    
                    listNodes[listNodes[stringBeforeCurrentUserInputInAlphabeticalOrder].next].last = a;
                    listNodes[stringBeforeCurrentUserInputInAlphabeticalOrder].next = a;
                    
                }
                
            }
            a = a + 1; // increment to the next freeNode
            thisStringShouldGoFirst = 0;
            
            /*
             * potential bug
             */
            for (int i = 0; i <= 15; ++i)
            {
                wordToDelete[i] = currentUserInput[i];
            }
        }
	} // end of while
	return 0;
}
