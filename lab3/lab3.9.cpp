#include <stdio.h>

int main() {

    int n_days, day;

    float initialbudget, remainingbudget, dailyspend;

    if (scanf("%f %d", &initialbudget, &n_days) != 2) {

        return 1;
    }

    remainingbudget = initialbudget;

    
    printf("Day | Spend | Remaining\n");

    printf("-------------------------\n");

    for (day = 1; day <= n_days; day++) {
        
        dailyspend = 0.0;

        
        if (remainingbudget >= 500.00) {

            dailyspend = 100.00;

        } else if (remainingbudget >= 100.00) {

            dailyspend = 50.00;  

        } else if (remainingbudget > 0) {

            dailyspend = 20.00;  

        } else {

            dailyspend = 0.00;   
        }

        
        if (dailyspend > remainingbudget) {

            dailyspend = remainingbudget;
        }

        remainingbudget -= dailyspend;

        printf("%d | %.2f | %.2f\n", day, dailyspend, remainingbudget);
        
        
        if (remainingbudget <= 0 && day < n_days) {
            break;
        }
    }

    printf("-------------------------\n");
    
    
    printf("Final Budget: %.2f\n", remainingbudget);

    return 0;
}