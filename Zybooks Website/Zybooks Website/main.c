#include <stdio.h>
// FIXME include the string library
#include <string.h>

int main(void) {
    
    /* Type your code here. */
    char userWord[50] = "";
    char userWord1[50] = "";
    int price = 0;
    int price1 = 0;
    
    printf("Davy's auto shop services\nOil change -- $35\nTire rotation -- $19\nCar wash -- $7\nCar wax -- $12\n");
    printf("\n");
    printf("Select first service: ");
    fgets(userWord, sizeof(userWord), stdin);
    printf("\n");
    printf("\n");
    
    printf("Select second service: ");
    fgets(userWord1, sizeof(userWord1), stdin);
    printf("\n");
    printf("\n");
    printf("\n");
    
    printf("Davy's auto shop invoice\n");
    printf("\n");
    
    if (strcmp(userWord, "Oil change\n") == 0) {
        strcpy(userWord, "Oil change");
        price = 35;
    } else if (strcmp(userWord, "Tire rotation\n") == 0) {
        strcpy(userWord, "Tire rotation");
        price = 19;
    } else if (strcmp(userWord, "Car wash\n") == 0) {
        strcpy(userWord, "Car wash");
        price = 7;
    } else if (strcmp(userWord, "Car wax\n") == 0) {
        strcpy(userWord, "Car wax");
        price = 12;
    } else if (strcmp(userWord, "-\n") == 0){
        strcpy(userWord, "-");
        price = 0;
    } else {
        // Do nothing
    }
    
    if (strcmp(userWord1, "Oil change\n") == 0) {
        strcpy(userWord1, "Oil change");
        price1 = 35;
    } else if (strcmp(userWord1, "Tire rotation\n") == 0) {
        strcpy(userWord1, "Tire rotation");
        price1 = 19;
    } else if (strcmp(userWord1, "Car wash\n") == 0) {
        strcpy(userWord1, "Car wash");
        price1 = 7;
    } else if (strcmp(userWord1, "Car wax\n") == 0) {
        strcpy(userWord1, "Car wax");
        price1 = 12;
    } else if (strcmp(userWord1, "-\n") == 0){
        strcpy(userWord1, "-");
        price1 = 0;
    } else {
        // No price
    }
    
    
    if ((strcmp(userWord, "-")) == 0) {
        printf("Service 1: No service\n");
    } else {
        printf("Service 1: %s", userWord);
        printf(", $%d\n", price);
    }
    
    if ((strcmp(userWord1, "-") == 0)) {
        printf("Service 2: No service\n");
    } else {
        printf("Service 2: %s", userWord1);
        printf(", $%d\n", price1);
    }
    
    printf("\n");
    printf("Total: $%d\n", (price + price1));
    
    return 0;
}
