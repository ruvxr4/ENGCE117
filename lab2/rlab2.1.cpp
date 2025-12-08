#include <stdio.h>

void reverse( char str1[], char str2[]);

int main(){

    char text[50] = "hola amigo";

    char out[50];

    reverse(text, out);

    return 0;
}


void reverse( char str1[], char str2[]){

    int i, j;

    for(i = 0; str1[i] != '\0'; i++);

    j = i - 1;

    for(i = 0; j >= 0; i++, j--){

        str2[i] = str1[j];
    }

    str2[i] = '\0';

    printf("Reversed string: %s\n", str2);
}