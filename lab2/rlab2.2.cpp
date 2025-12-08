#include <stdio.h>

char* reverse(char str1[]);

int main(){

    char text[50] = " HoLa Amigo";

    char *out;

    out = reverse(text);

    return 0;
}

char* reverse(char str1[]){

    static char str2[50]; // Static จะไม่โดนลบตอนฟังก์จบ

    int i, j;

    for(i = 0; str1[i] != '\0'; i++); //หาความยาวstring

    j = i - 1;

    for(i = 0; j >= 0; i++, j--){

        str2[i] = str1[j];
    }

    str2[i] = '\0';

    printf("Reversed string: %s\n", str2);

    return str2;
}