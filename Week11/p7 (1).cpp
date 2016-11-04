// Brandon J. Fletcher
// CS 2433: C/C++ Programming
// 2016 Fall Semester
// Assignment: program7
// Due date: October 27, 2016
// Date submitted: October 27, 2016
// Instructor: Richard Churchill

/*************************************************
 *  Build Instructions:				 *
 *	•Open a Terminal on Unix/Linux System.	 *
 *	•Change Directories to p7.cpp location   *
 *	•Use: g++ -o p7a p7.cpp (to compile)     *
 *	•Run: ./p7a will run the program         *
 *                                               *
 *************************************************/

#include <iostream>
#include <iomanip> // used for setprecision
#include <stdlib.h> // for to_string()
#include <string>
using namespace std;

class RecordV {
    public:
        void SetName(string nameV); // Set private variable name
        string GetName();
        double groceryInfo[5];
    private:
        string name;
    
};

// Method Used as Setter of Private Variable Name
void RecordV::SetName(string nameV) {
    name = nameV;
    return;
}

// Method Used as Getter of Private Variable Name
string RecordV::GetName() {
    return name;
}

int main() {
    int numObjToCreate = 0;
    string object = "object";
    string objectItem = "";
    string namesOfItems[4] = {"", "", "", ""}; // We can assume this due to a max of 4 objects
    double valuesOfObjects[20]; // Will be at most 20 values
    double userInputToMultiply = 0.00; // What we shall multiply objects by
    
    cout << "How man objects shall we create today: ";
    cin >> numObjToCreate;
    cout << endl;
    
    // if < 2 || > 4 exit program
    if (numObjToCreate < 2 || numObjToCreate > 4) {
        exit(0);
    }
    
    cout << "Okay, we shall creat " << numObjToCreate << " objects." << endl;
    
    // for loop of objects
    
    for (int i = 0; i < numObjToCreate; i++) {
        int j = 0;
        if (i == 1) {
            j = 5;
        }
        else if (i == 2) {
            j = 10;
        }
        else if (i == 3) {
            j = 15;
        }
        else {
            j = i;
        }
        cout << "Name of Grocery Item: ";
        cin >> namesOfItems[i];
        cout << endl;
        
        // for Price
        cout << "Price of Grocery Item: ";
        cin >> valuesOfObjects[0 + j];
        cout << endl;
        
        // for Unit size
        cout << "Unit Size of Grocery Item: ";
        cin >> valuesOfObjects[1 + j];
        cout << endl;
        
        // for Quantity
        cout << "Quantity of Grocery Item: ";
        cin >> valuesOfObjects[2 + j];
        cout << endl;
        
        // for Decay factor
        cout << "Decay Factor of Grocery Item: ";
        cin >> valuesOfObjects[3 + j];
        cout << endl;
        
        // for Decay period
        cout << "Decay Period of Grocery Item: ";
        cin >> valuesOfObjects[4 + j];
        cout << endl;
        
        
    }
    
    for (int i = 0; i < numObjToCreate; i++) {
	
        if (i == 0) {
            object = "object0";
	   }
	   else if (i == 1) {
	        object = "object1";
	   }
	   else if (i == 2) {
	       object = "object2";
	   }
	   else {
	       object = "object3";
	   }
        // cout << object << endl;
        RecordV object;
        
        int j = 0;
        if (i == 1) {
            j = 5;
        }
        else if (i == 2) {
            j = 10;
        }
        else if (i == 3) {
            j = 15;
        }
        else {
            j = i;
        }
        
        object.SetName(namesOfItems[i]);
        object.groceryInfo[0] = valuesOfObjects[0 + j]; // Price
        object.groceryInfo[1] = valuesOfObjects[1 + j]; // Unit Size
        object.groceryInfo[2] = valuesOfObjects[2 + j]; // Quantity (tonnes)
        object.groceryInfo[3] = valuesOfObjects[3 + j]; // Decay factory
        object.groceryInfo[4] = valuesOfObjects[4 + j]; // Decay period
        
        
        cout << "                Name: " << object.GetName() << endl;
        cout << "               Price: $" << setprecision(3) << object.groceryInfo[0] << endl;
        cout << "      Unit size (kg): " << setprecision(3) << object.groceryInfo[1] << endl;
        cout << "   Quantity (tonnes): " << setprecision(3) << object.groceryInfo[2] << endl;
        cout << "       Decay factory: " << setprecision(3) << object.groceryInfo[3] << endl;
        cout << " Decay period (days): " << setprecision(3) << object.groceryInfo[4] << endl;
        
        cout << endl << endl;
        
    }
    
    // Changing the first Object/Instance
    cout << "We are going to need you to rename the first Grocery Item, what shoulds we chang it to: ";
    cin >> namesOfItems[0];
    cout << endl;
    
    // Reprinting It
    RecordV objectReReferance;
    objectReReferance.SetName(namesOfItems[0]);
    objectReReferance.groceryInfo[0] = valuesOfObjects[0]; // Price
    objectReReferance.groceryInfo[1] = valuesOfObjects[1]; // Unit Size
    objectReReferance.groceryInfo[2] = valuesOfObjects[2]; // Quantity (tonnes)
    objectReReferance.groceryInfo[3] = valuesOfObjects[3]; // Decay factory
    objectReReferance.groceryInfo[4] = valuesOfObjects[4]; // Decay period
    
    
    cout << "                Name: " << objectReReferance.GetName() << endl;
    cout << "               Price: $" << setprecision(3) << objectReReferance.groceryInfo[0] << endl;
    cout << "      Unit size (kg): " << setprecision(3) << objectReReferance.groceryInfo[1] << endl;
    cout << "   Quantity (tonnes): " << setprecision(3) << objectReReferance.groceryInfo[2] << endl;
    cout << "       Decay factory: " << setprecision(3) << objectReReferance.groceryInfo[3] << endl;
    cout << " Decay period (days): " << setprecision(3) << objectReReferance.groceryInfo[4] << endl;
    
    // Obtaining Double
    cout << "Give me a double to multiply all doubles by: ";
    cin >> userInputToMultiply;
    cout << endl;
    
    // Changing Doubles in Array
    for (int i = 0; i < 20; i++) {
        valuesOfObjects[i] = valuesOfObjects[i] * userInputToMultiply;
    }
    
    // Reprint Objects
    for (int i = 0; i < numObjToCreate; i++) {
        if (i == 0) {
            object = "object0";
         }
        else if (i == 1) {
         object = "object1";
        }
        else if (i == 2) {
            object = "object2";
        }
        else {
            object = "object3";
        }
        // cout << object << endl;
        RecordV object;
        
        int j = 0;
        if (i == 1) {
            j = 5;
        }
        else if (i == 2) {
            j = 10;
        }
        else if (i == 3) {
            j = 15;
        }
        else {
            j = i;
        }
        
        object.SetName(namesOfItems[i]);
        object.groceryInfo[0] = valuesOfObjects[0 + j]; // Price
        object.groceryInfo[1] = valuesOfObjects[1 + j]; // Unit Size
        object.groceryInfo[2] = valuesOfObjects[2 + j]; // Quantity (tonnes)
        object.groceryInfo[3] = valuesOfObjects[3 + j]; // Decay factory
        object.groceryInfo[4] = valuesOfObjects[4 + j]; // Decay period
        
        
        cout << "                Name: " << object.GetName() << endl;
        cout << "               Price: $" << setprecision(3) << object.groceryInfo[0] << endl;
        cout << "      Unit size (kg): " << setprecision(3) << object.groceryInfo[1] << endl;
        cout << "   Quantity (tonnes): " << setprecision(3) << object.groceryInfo[2] << endl;
        cout << "       Decay factory: " << setprecision(3) << object.groceryInfo[3] << endl;
        cout << " Decay period (days): " << setprecision(3) << object.groceryInfo[4] << endl;
        
        cout << endl << endl;
        
    }
    
    return 0;
}
