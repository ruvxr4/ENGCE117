#include <stdio.h>

int main() {
    int n_calculations, i;

    int attklv1, opplv1, opparmor;

    float baseatk, dmgreduc, netdmg, damagedeficit;

    
    float worth_threshold = 150.0; 

    if (scanf("%d", &n_calculations) != 1) {

        return 1;
    }

    for (i = 0; i < n_calculations; i++) {
        
        if (scanf("%d %d %d", &attklv1, &opplv1, &opparmor) != 3) {
            
            break;
        }

        baseatk = attklv1 * 10.0;

        if (opparmor < 50) {

            dmgreduc = 0.20;

        } else {

            dmgreduc = 0.40;
        }

        netdmg = baseatk * (1.0 - dmgreduc);

        
        if (netdmg >= worth_threshold) {
           
            printf("SUCCESS! Net Damage: %.2f\n", netdmg);
            
        } else {

            damagedeficit = worth_threshold - netdmg;
            
            printf("FAIL. Deficit: %.2f\n", damagedeficit);
        }
    }

    return 0;
}