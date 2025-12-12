#include <stdio.h>

#include <windows.h>



int main() {
    SetConsoleOutputCP(65001); //รันแล้วจะได้อ่านภาษาไทยได้
    int customerType;

    float consumption_kwh, totalBill = 0.0;

    printf("Enter Customer Type (1 for ครัวเรือน, 2 for ธุรกิจ and Consumption in kWh: ");

    scanf("%d %f", &customerType, &consumption_kwh);

    if (customerType == 1) {
       
        if (consumption_kwh <= 100) {

            totalBill = consumption_kwh * 3.0;

        } else {
           
            totalBill = consumption_kwh * 4.0;
        }

        printf("Total Bill: %.2f\n", totalBill);

    } else if (customerType == 2) {
        
        if (consumption_kwh <= 500) {

            totalBill = consumption_kwh * 5.0;
        } else {
            
            totalBill = consumption_kwh * 6.5;
        }

        printf("Total Bill: %.2f\n", totalBill);

    } else {
        
        printf("Invalid Customer Type\n");
    }

    return 0;
}