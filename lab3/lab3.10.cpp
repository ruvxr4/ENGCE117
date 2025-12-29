#include <stdio.h>


struct Item {

    char name[50];

    float unitPrice;

    int quantity;

}typedef it;

int main() {

    int n, i;

    float subTotal = 0.0;   

    float vatRate = 0.07;     
    
    float totalVAT;

    float grandTotal;

    if (scanf("%d", &n) != 1) {

        return 1;
    }

    it items[n];

    
    printf("--- RECEIPT ---\n");

    for (i = 0; i < n; i++) {

        float itemCost;

        if (scanf("%s %f %d", items[i].name, &items[i].unitPrice, &items[i].quantity) != 3) {

            return 1;
        }

        itemCost = items[i].unitPrice * items[i].quantity;

        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, itemCost);

        subTotal += itemCost; 
    }

    
    totalVAT = subTotal * vatRate;     
    
    grandTotal = subTotal + totalVAT;  

    printf("--------------------\n");

    printf("Subtotal: %.2f\n", subTotal);

    printf("VAT (7%%): %.2f\n", totalVAT);

    printf("Grand Total: %.2f\n", grandTotal);
    

    return 0;
}