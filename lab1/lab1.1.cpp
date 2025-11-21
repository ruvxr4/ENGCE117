#include <stdio.h>


int main() {

    int N, i;
    
    printf("enter ur number:\n");

    if (scanf("%d", &N) != 1) {
        return 1; 
    }
    
    for(i = 1; i <= N; i++){
        printf("Hello Loop!\n");
    }

    

    return 0;
}