// Brandon J. Fletcher
// CS 2433: C/C++ Programming
// 2016 Fall Semester
// Assignment: program3
// Due date: September 08, 2016
// Date submitted: September 07, 2016
// Instructor: Richard Churchill

/******************************************************************
 *   Build Instructions:                                          *
 *                                                                *
 *      •Open a Terminal on Unix/Linux System                     *
 *      •Change Directories to p3.c File Location                 *
 *      •NOTE -- the import of stdlib.h below!                    *
 *      •Use "gcc -o p3a p3.c" to compile the C file              *
 *      •Then, to run the C program us ./p3a                      *
 *                                                                *
 *                                                                *
 *                                                                *
 *                                                                *
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
 * Function to be used by qsort() later in the program.
 * can be found @cplusplus.com documentation as an example
 * algorithm for the qsort() function.
 */

int compareFunction(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}


int
main(void)
{
    int listToSort[100];
    int arrayIndex = 0; // allows program to know the full length of the array
    int userValue = 0; // changes for each input given by user to add to the array
    
    while (arrayIndex < 100)
    {
        
        printf("Enter an Integer Please: ");
        scanf("%d", &userValue);
        
        if(userValue > 0)
        {
            listToSort[arrayIndex] = userValue;
            arrayIndex++;
        }
        else
        {
            if (arrayIndex == 0)
            {
                printf("\n\n\nMust enter positive Integers to get a sorted list.\n");
                printf("Starting by entering a negative integer or zero will end the program.\n");
                printf("Retry!\n\n\n");
                break;
            }
            else
            {
                break;
            }
        }
    }
    
    /**
     * implementation of the qsort() built into the stdlib.h library
     */
    
    qsort(listToSort, arrayIndex, sizeof(int), compareFunction);
    
    // prints the now sorted array of integers entered by the user
    
    for (int i = 0; i < arrayIndex; i++)
    {
        printf("%d\n", listToSort[i]);
    }
    
    return 0;
}