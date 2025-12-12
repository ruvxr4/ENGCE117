#include <stdio.h>

void explode(char str_1[], char splitter, char str_2[][10], int *count);

int main() {

    char out[20][10];
    
    int num;

    explode("I/Love/You", '/', out, &num);

    printf("\nTotal substrings = %d\n", num);

    return 0;
}

void explode(char str_1[], char splitter, char str_2[][10], int *count) {

    int i = 0, j = 0;

    *count = 0;

    for (i = 0; str_1[i] != '\0'; i++) {

        if (str_1[i] == splitter) {

            str_2[*count][j] = '\0'; 

            (*count)++;   

            j = 0;                     

        } else {

            str_2[*count][j] = str_1[i];

            j++;
        }
    }

    str_2[*count][j] = '\0';

    (*count)++;

    for (i = 0; i < *count; i++) {

        printf("str2[%d] = \"%s\"\n", i, str_2[i]);
    }
}
