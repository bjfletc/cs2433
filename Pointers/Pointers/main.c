//
//  main.c
//  Pointers
//
//  Created by Brandon Fletcher on 10/4/16.
//  Copyright © 2016 Brandon Fletcher. All rights reserved.
//

#include <stdio.h>


void hello(int *inputPointer) {
    *inputPointer = 20;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int *pointer = 10;
    //int *pointer2 = 22;
    printf("%p\n", pointer);
    
    hello(pointer);
    
    printf("%d\n", *pointer);
    
    
    return 0;
}

