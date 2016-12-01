/*****************************************************************************************************
 * Brandon J. Fletcher                                                                                *
 * E-mail: brandon.fletcher@okstate.edu                                                               *
 * CS 2433: C/C++ Programming                                                                         *
 * 2016 Fall Semester                                                                                 *
 * Assignment: program9                                                                               *
 * Due date: November 28, 2016                                                                        *
 * Date submitted: November 28, 2016                                                                  *
 * Instructor: Richard Churchill                                                                      *
 *                                                                                                    *
 *  Build Instructions:                                                                               *
 *      •Open a Terminal on Unix/Linux System.                                                        *
 *      •Change Directories to p9.cpp location                                                        *
 *      •Use: g++ -o p9a p9.cpp (to compile)                                                          *
 *      •Run: ./p9a will run the program                                                              *
 *                                                                                                    *
 ******************************************************************************************************/

#include <iostream>
#include "SetClass.h"

using namespace std;

/*** Print class definition ***/

class Print {
    friend class SetClass;
    
    public:
        void print(SetClass a);
    private:
        int count;
};

void Print::print(SetClass classToPrint) {
    count = 0;
    
    for (int i = 0; i < 51; ++ i) {
        if (classToPrint.isElement(i) == true) {
            cout << i << " == true" << endl;
            count += 1;
        } else {
            // Do Nothing
        }
    }
    
    if (count == 0) {
        cout << "Set is empty" << endl;
    } else {
        count = 0;
    }
    
} // End of print() Method

/*** End definitions for Print class ***/

int main() {
    
    SetClass A;
    SetClass B;
    SetClass C;
    Print printer; // friend class of SetClass
    int currentUserInputA;
    int currentUserInputB;
    int currentUserInputCheck;
    
    /*** Implement Printing of Sets A, B, & C ***/
    cout << "A ";
    printer.print(A);
    cout << endl;
    cout << "B ";
    printer.print(B);
    cout << endl;
    cout << "C ";
    printer.print(C);
    cout << endl;
    
    
    while (currentUserInputA != -1) {
        cout << "Enter Integers to Fill Set A [-1 to Quit]: ";
        cin >> currentUserInputA;
        A.add(currentUserInputA);
        
        
        cout << endl;
    }
    
    while (currentUserInputB != -1) {
        cout << "Enter Integers to Fill Set B [-1 to Quit]: ";
        cin >> currentUserInputB;
        B.add(currentUserInputB);
        
        
        cout << endl;
    }
    
    currentUserInputB = 0; // Changed for Remove Capability Down Below
    
    /*** Printing A & B Data Members ***/
    cout << "Printing A's Data Set: " << endl;
    printer.print(A);
    cout << endl;
    
    cout << "Printing B's Data Set: " << endl;
    printer.print(B);
    cout << endl;
    
    /*** Read Set of Numbers to Remove From B ***/
    while (currentUserInputB != -1) {
        cout << "Enter Integers to Remove From Set B [-1 to Quit]: ";
        cin >> currentUserInputB;
        B.remove(currentUserInputB);
        
        
        cout << endl;
    }
    
    cout << "Printing A's Data Set: " << endl;
    printer.print(A);
    cout << endl;
    
    cout << "Printing B's Data Set: " << endl;
    printer.print(B);
    cout << endl;
    
    /*** Case C = A + B ***/
    
    /*** Case C = A * B ***/
    
    /*** Case C = -B ***/
    
    /*** Check Set A, B, C For currentUserInputCheck ***/
    cout << "Enter an Integer to see if it is in Sets A, B, or C: ";
    cin >> currentUserInputCheck;
    cout << endl;
    
    if (A.isElement(currentUserInputCheck) == true) {
        cout << "Found in Set A!" << endl;
    } else {
        cout << currentUserInputCheck << " does not exist in A!" << endl;
    }
    
    if (B.isElement(currentUserInputCheck) == true) {
        cout << "Found in Set B!" << endl;
    } else {
        cout << currentUserInputCheck << " does not exist in B!" << endl;
    }
    
    if (C.isElement(currentUserInputCheck) == true) {
        cout << "Found in Set C!" << endl;
    } else {
        cout << currentUserInputCheck << " does not exist in C!" << endl;
    }
    
    return 0;
}
