#include <stdio.h>

int main() {
    int N, i;

    int studentId, score, totalclasses, absentclasses;

    float attendancepercent;

    int passcount = 0;

    int failcount = 0;

    if (scanf("%d", &N) != 1) {
        
        return 1;
    }

    for (i = 0; i < N; i++) {
        if (scanf("%d %d %d %d", &studentId, &score, &totalclasses, &absentclasses) != 4) {
            break;
        }

        
        attendancepercent = ((float)(totalclasses - absentclasses) / totalclasses) * 100.0;

        
        int isScorePass = (score >= 50); 

        int isAttPass = (attendancepercent >= 75.0);

        printf("Student %d: ", studentId);

        
        if (isScorePass && isAttPass) {
            
            printf("PASS\n");

            passcount++;

        } else {
            
            printf("FAIL - ");

            failcount++;

            if (!isScorePass && !isAttPass) {
                
                printf("Both Score and Attendance\n");

            } else if (!isScorePass) {
                
                printf("Low Score\n");

            } else {
            
                printf("Low Attendance (%.2f%%)\n", attendancepercent);
            }
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passcount);
    printf("Total FAIL: %d\n", failcount);

    return 0;
}