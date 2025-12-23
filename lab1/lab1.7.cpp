#include <stdio.h>

int main() {

    int cType;

    float unit, bill = 0.0;

 
    if (scanf("%d %f", &cType, &unit) != 2) {

        return 1; 

    }

    
    if (cType == 1) {
    
        if (unit <= 100) {

            bill = unit * 3.0;
            
        } else {

            bill = unit * 4.0;
        }
        
        printf("Total Bill: %.2f\n", bill);

    } else if (cType == 2) {
        
        if (unit <= 500) {

            bill = unit * 5.0;

        } else {

            bill = unit * 6.5;
        }

        printf("Total Bill: %.2f\n", bill);

    } else {
        
        printf("Invalid Customer Type\n");
    }

    return 0;
}
