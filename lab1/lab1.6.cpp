#include <stdio.h>

int main(){

    int number;

    do{

        printf("input a number (1-10): ");


        if(scanf("%d", &number) != 1){

            break;
        }

        if(number < 1 || number > 10){

            printf("error: number must be 1-10.\n");

        }

    } while(number < 1 || number > 10);

    printf("input accepted:%d\n", number);

    return 0;
}