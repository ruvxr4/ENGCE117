#include <stdio.h>

char* reverse(char str_1[]);

int main(){
    
    char text[50] = " HoLa Amigo";

    char *out;

    out = reverse(text);

    return 0;
}

char* reverse(char str_1[]){
    
    static char str_2[50]; 

    int i, j;

    int len = 0; 

    i = 0;

    while (str_1[i] != '\0') {

        i++;
    }
    
    len = i;   

    j = len - 1; 

    for(i = 0; j >= 0; i++, j--){

        str_2[i] = str_1[j];
    }

    str_2[i] = '\0'; 

    printf("Reversed string: %s\n", str_2);

    return str_2;
}
