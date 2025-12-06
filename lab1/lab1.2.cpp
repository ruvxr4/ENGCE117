#include <stdio.h>

void grade_calculator(int score);

int main(){

    int score;


    printf("enter ur score here:");

    if(scanf("%d", &score) !=1){

        printf("try again\n");

        return 1;
    }

    grade_calculator(score);

    return 0;
}

void grade_calculator(int score){

    if(score >= 80){
        printf("grade A\n");
    } else if(score >= 70){
        printf("grade B\n");
    } else if(score >= 60){
        printf("grade C\n");
    } else if(score >= 50){
        printf("grade D\n");
    } else if(score < 50){
        printf("grade F\n");
    }

}