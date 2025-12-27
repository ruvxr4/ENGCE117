#include <stdio.h>


struct product{

    char name[50];

    int productId;

    float price;

}typedef P ;


int main(){

    struct product item;

    if(scanf("%d %f %s",&item.productId, &item.price, item.name) != 3){

        return 1;
    }

    printf("id:%d, price:%.2f, name:%s",item.productId, item.price, item.name);

    return 0;
}

