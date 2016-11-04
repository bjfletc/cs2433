// Brandon J. Fletcher
// CS 2433: C/C++ Programming
// 2016 Fall Semester
// Assignment: program2
// Due date: September 01, 2016
// Date submitted: ...
// Instructor: Richard Churchill

/*****************************************************************
*   Build Instructions:                                          *
*                                                                *
*      •Open a Terminal on Unix/Linux System                     *
*      •Change Directories to p2.c File Location                 *
*      •Use "gcc -o p2a p2.c" to compile the C file              *
*      •Then, to run the C program us ./p2a                      *
*                                                                *
*                                                                *
*                                                                *
*                                                                *
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define TRUE -1
#define FALSE 0

int main(void)
{

    int n; //variable to be obtained from User later
    int count; //used for while loop to define location in loop
    int whileLoopFactorial;
    int whileExponentValue = 1;
    int forLoopFactorial = 1;
    int forExponentValue = 1;

    //Prompt User for an Integer value & store it in 'n'
    printf("\n\nEnter an Integer: ");
    scanf("%d", &n);

    if (n > 0)
    {
        
        //computing the whileLoopFactorial on n
        whileLoopFactorial = n;
        count = n - 1;
        
        while (count > 1)
        {
            //Calculating n! factorial using while loop
            whileLoopFactorial = whileLoopFactorial * count;
            count--;
        }
        
        printf("\n\nValue of %d! computed using while loop is %d\n", n, whileLoopFactorial);
        
        //Calculate 2^n power using a while loop
        int i = 0;
        
        while (i < n)
        {
            //2^n using a while loop
            whileExponentValue = 2 * whileExponentValue;
            i++;
        }
        
        printf("Value of 2 to the power of %d computed using while loop is %d\n", n, whileExponentValue);
        
        //whileExponentValue/whileLoopFactorial computation
        printf("The ratio of %d! to 2 to the power %d is %.2f\n", n, n, (whileLoopFactorial/(whileExponentValue*1.0)));

        //forLoopFactorial computation
        count = n;
        for (int i = count; i > 0; i--)
        {
        	forLoopFactorial = forLoopFactorial * i;
        }

        printf("Value of %d! computed using for loop is %d\n", n, forLoopFactorial);

        //Calculate 2^n power using a for loop
        
        for (int i = 1 ; i <= n; i++)
        {
            forExponentValue = 2 * forExponentValue;
        }
        
        printf("Value fo 2 to the power %d computed using for loop is %d\n", n, forExponentValue);
        
        //forExponentValue/forLoopFactorial computation
        
        printf("Value of %d! to 2 to the power %d is %.2f\n", n, n, (forLoopFactorial/(forExponentValue*1.0)));
    }
    else
    {
    	printf("Please enter a non-negative Integer.\n");
    }
    
    //end of main
    return 0;
}