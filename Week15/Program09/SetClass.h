#include <iostream>

using namespace std;

/*** SetClass class definition ***/


class SetClass {
    public:
        bool isEmpty(int x);
        bool isElement(int x);
        bool add(int x);
        bool remove(int x);
        SetClass(); // Default constructor
    
    private:
        bool set[51];
};

/*** SetClass Default Constructor ***/
SetClass::SetClass() {
    
    for (int i = 0; i < 51; ++i) {
        set[i] = false;
    }
    
    return;
}

bool SetClass::isEmpty(int checkForTrue) {
    
    /**
         returns true if the Set is empty, false otherwise
     */
    
    if (set[checkForTrue] == true) {
        return true;
    } else {
        return false;
    }
    
} // End of isEmpty() Method

bool SetClass::isElement(int isElementTest) {
    
    /**
         returns true if x is a member of the set, false otherwise
     */
    
    if (set[isElementTest] == true) {
        return true;
    } else {
        return false;
    }
} // End of isElement() Method

bool SetClass::add(int elementToAdd) {
    
    /**
         adds x to the set. If x is already a member or out of range, return
         false, otherwise return true.
     */
    
    int currentElement = elementToAdd;
    
    if (currentElement < 0) {
        cout << "ERROR MESSAGE: Integer Out of Bounds ~0 -- 50~" << endl;
        return false;
    } else if (currentElement > 50) {
        cout << "ERROR MESSAGE: Integer Out of Bounds ~0 -- 50~" << endl;
        return false;
    } else {
        // Reached A Comprehensible Stage
        
        if (set[currentElement] == true) {
            cout << "ERROR MESSAGE: " << currentElement << " is already a member." << endl;
            return false;
        } else {
            set[currentElement] = true;
            return true;
        }
    }
} // End of add() Method

bool SetClass::remove(int elementToRemove) {
    
    /**
         removes x from the set. If x was in the set (before removal), return
         true indicating the removal is successful, otherwise return false
     */
    
    if (elementToRemove < 0) {
        cout << "ERROR MESSAGE: Integer Out of Bounds ~0 -- 50~" << endl;
        return false;
    } else if (elementToRemove > 50) {
        cout << "ERROR MESSAGE: Integer Out of Bounds ~0 -- 50~" << endl;
        return false;
    } else {
        // Reached A Comprehensible Stage
        
        if (set[elementToRemove] == false) {
            cout << "ERROR MESSAGE: " << elementToRemove << " is not a member." << endl;
            return false;
        } else {
            set[elementToRemove] = false;
            return true;
        }
    }
} // End of remove() Method


/*** End definitions for SetClass class ***/

/*** Creation of Operators ***/

SetClass operator+ (SetClass a, SetClass b) {

	SetClass c;
	
	for (int i = 0; i < 51; ++i) {
		if (a.isElement(i) || b.isElement(i)) {
			c.add(i);
		}
	}
	
	return c;
}

SetClass operator* (SetClass a, SetClass b) {
	SetClass c;
	
	for (int i = 0; i < 51; ++i) {
		if (a.isElement(i) && b.isElement(i)) {
			c.add(i);
		}
	}
	
	return c;
}

SetClass operator- (SetClass b) {
	
	for (int i = 0; i < 51; ++i) {
		if (b.isElement(i)) {
			b.remove(i);
		} else {
			b.add(i);
		}
	}
	
	return b;
	
}
