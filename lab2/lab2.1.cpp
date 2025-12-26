#include <stdio.h>

void checkloop(int N);


int main(){

    int N, i;

    if (scanf("%d", &N) != 1) {

        return 1;
    }

    checkloop(N);

    return 0;

}


void checkloop(int N){

    for (int i = 0; i < N; i++){

        printf("Hello Loop!\n");

    }
}