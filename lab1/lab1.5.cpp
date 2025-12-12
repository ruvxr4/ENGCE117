#include <stdio.h>

int main(){

    int number, evensum = 0, oddsum = 0;

    if(scanf("%d", &number) != 1){

        printf("error, try again.\n");

        return 1;
    }

    while(number != 0){

        if(number % 2 == 0){

            evensum += number;

        } else {

            oddsum += number;

        }
        

        if(scanf("%d", &number) != 1){

            break;
        }
    }

    printf("even sum: %d\n", evensum);

    printf("odd sum: %d\n", oddsum);

    return 0;

}