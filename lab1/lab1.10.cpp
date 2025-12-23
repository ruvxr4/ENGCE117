#include <stdio.h>

int main() {
    
    int clearanceLevel, age, isActive;

    
    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3) {
       
        return 1;

    }

    
    int condition1 = (clearanceLevel == 3 && isActive == 1);
    
    int condition2 = (clearanceLevel == 2 && age >= 25 && isActive == 1);

    
    if (condition1 || condition2) {

        printf("Access Granted");
    } else {
        
        printf("Access Denied");
    }

    return 0;
}