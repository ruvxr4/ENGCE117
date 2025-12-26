#include <stdio.h>

int main() {
    
    int termCode;

    float investmentAmount;

    float aprRate = 0.0;

    float totalInterest = 0.0;
    
    int isValid = 1;

    if (scanf("%d %f", &termCode, &investmentAmount) != 2) {

        return 1;
    }


    switch (termCode) {
        case 1: 
            
            if (investmentAmount < 5000) {

                aprRate = 0.03; 

            } else {

                aprRate = 0.04; 

            }

            break;

        case 2: 
            if (investmentAmount < 10000) {

                aprRate = 0.05; 

            } else {

                aprRate = 0.065; 
            }

            break;

        case 3: 

            aprRate = 0.08; 

            break;

        default: 

            isValid = 0; 

            printf("Invalid Term Code\n");
    }

    
    if (isValid == 1) {

        totalInterest = investmentAmount * aprRate;

        printf("%.2f\n", totalInterest);
    }

    return 0;
}