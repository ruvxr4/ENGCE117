#include <stdio.h>

void calculator(int num1, int num2, int operationcode);

int main(){

    int num1, num2, result, operationcode;

    printf("Calculator\n");

    printf("input number and operationcode(1:+, 2:-, 3:*, 4:/): ");

    if(scanf("%d %d %d", &num1, &num2, &operationcode) != 3){
        
        printf("error, try again.\n");
        
        return 1;

    }

    calculator(num1, num2, operationcode);

    return 0;


}

void calculator(int num1, int num2, int operationcode){

    int result;

    switch(operationcode){

        case 1:
            result = num1 + num2;

            printf("Result: %d\n", result);

            break;

        case 2:
            result = num1 - num2;

            printf("Result: %d\n", result);

            break;

        case 3:
            result = num1 * num2;

            printf("Result: %d\n", result);

            break;

        case 4:
            if(num2 == 0){

                printf("error, try again.\n");

            } else {
                result = num1 / num2;

                printf("Result: %d\n", result);
            }
            break;

        default:
            printf("error, try again.\n");

            break;
    }
}