#include <stdio.h>

int find_sum(int N);

int main(){

    int N, sum = 0, i;

    printf("input num here:");

    if(scanf("%d", &N) != 1){

        printf("error, try again.\n");

        return 1;
    }

    sum = find_sum(N);

    printf("%d\n", sum);

    return 0;

}

int find_sum(int N){

    int sum = 0;

    for(int i = 1; i <= N; i++){

        sum += i;

    }

    return sum;

}