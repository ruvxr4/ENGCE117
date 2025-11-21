#include <stdio.h>

void print_hello_loop(int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Hello Loop!\n");
    }
}

int main() {
    int input_number;

    printf("Please enter a positive integer: ");

    if (scanf("%d", &input_number) != 1) {
        printf("Error: Invalid input format. Please enter a number.\n");
        return 1; 
    }

    if (input_number < 0) {
        printf("Warning: The number is negative. No output will be displayed.\n");
    } else {
        print_hello_loop(input_number);
    }

    return 0;
}
