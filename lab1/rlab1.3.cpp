#include <stdio.h>

int *GetSet(int *num);

int main() {

    int *data, num;
    
    data = GetSet(&num);
    
    return 0;
}


int *GetSet(int *num) {
    int *data;

    printf("how many num do u want? : ");
    scanf("%d", num);

    data = new int[*num]; 

    for (int i = 0; i < *num; i++) {
        printf("Enter num %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    printf("You entered:\n");
    for (int i = 0; i < *num; i++) {
        printf("number %d: %d\n", i + 1, data[i]);
    }
    
    return data;
}
