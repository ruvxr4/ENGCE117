#include <stdio.h>

void print_hello_loop(int *count);
void check_negative(int *number);
void check_positive(int *number);

int main() {
    int input_number;

    check_positive(&input_number);

    check_negative(&input_number);


    return 0;
}

void print_hello_loop(int *count){

    int i;

    for (i = 0; i < *count; i++) {
        printf("Hello Loop!\n");
    }
}

void check_negative(int *checkposnum){

    if ( *checkposnum <= 0) {
        printf("error,try again.\n");
    } else {
        print_hello_loop(checkposnum);
    }
}

void check_positive(int *checknegnum){

    printf("Please enter a positive integer: ");

    if (scanf("%d", checknegnum) != 1) {
        printf("error,try again.\n");
    }

}
