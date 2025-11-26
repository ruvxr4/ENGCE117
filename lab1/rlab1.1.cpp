#include <stdio.h>

void print_hello_world(int *times);

int main(){

    int n;

    printf("enter ur number: ");

    scanf("%d", &n);
    
    print_hello_world(&n);

    return 0;

}

void print_hello_world(int *times){

    int i;
    for (i = 0; i < *times; i++) {
        printf("[%d] Hello world\n", i+1);
    }
}