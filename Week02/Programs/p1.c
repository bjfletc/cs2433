// Brandon J. Fletcher
// CS 2433: C/C++ Programming
// 2016 Fall Semester
// Assignment: program1
// Due date: August 23, 2016
// Date submitted: August 18, 2016
// Instructor: Richard Churchill

/*************************************************
*				Build Instructions:				 *
*	•Open a Terminal on Unix/Linux System.		 *
*	•Change Directories to p1.c File Location	 *
*	•Use: gcc -o p1a p1.c (to compile)			 *
*	•Run: ./p1a will run the program			 *
*												 *
*************************************************/

#include <stdio.h>

int main(void) {

	//ask user for an Integer value
	int n;

	printf("Please input an integer: ");
	scanf("%d", &n);
	//printf("\n%d\n", n);
	
	if (n >= 1) {

		if (n % 2 == 0) {
			printf("%d is even\n", n);
		}
		else {
			printf("%d is odd\n", n);
		}

		if (n % 11 == 0) {
			printf("%d is divisble 11.\n", n);
		}
		else {
			printf("%d is not modulo 11\n", n);
		}

		int m = n % 11;

		if (m % 2 == 0) {
			printf("%d modulo 11 is even\n", n);
		}
		else {
			printf("%d modulo 11 is odd\n", n);
		}
	}
	else {
		printf("The input you have entered is invalid, please enter a positve integer!\n");
	}
	

	return 0;
}