#include <stdio.h>

int main() {
    int N, i, quantity;

    float unitprice, itemcost, grandtotal = 0.0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        
        if (scanf("%f %d", &unitprice, &quantity) != 2) {

            return 1;
        }

       
        float costbeforediscount = unitprice * quantity;

        if (unitprice >= 1000.00) {
            
            itemcost = costbeforediscount * 0.90;

        } else {

            itemcost = costbeforediscount;
        }

        grandtotal += itemcost;

    }

    printf("Grand Total: %.2f\n", grandtotal);

    return 0;
}