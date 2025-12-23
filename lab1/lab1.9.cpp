#include <stdio.h>

int main(){

    int zonecode;

    float weight_kg;

    float totalcost = 0.0;

    if (scanf("%d %f", &zonecode, &weight_kg) != 2) {

        return 1;

    }

    switch(zonecode){
        case 1:
            if(weight_kg <= 5.0){
                
                totalcost = 50.0;

            } else {

                totalcost = 80.0;
            }

            break;

        case 2:
            if(weight_kg <= 10.0){

                totalcost = 150.0;
            } else {

                totalcost = 250.0;
            }

            break;

        case 3:
            totalcost = 500.0;

            break;

        default:
            
            printf("Invalid Input\n");
            return 0;
    }


    if(totalcost > 0.0 || zonecode >= 1 || zonecode <= 3){

        printf("Total Cost: $%.2f\n", totalcost);

    } else {

        printf("Invalid Input\n");

    }

    return 0;


}