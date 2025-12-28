#include <stdio.h>

struct Student {

    char name[50];

    int studentId;

    float score;
}typedef ss;

int main() {
    int N, i;

    float totalScore = 0.0;

    float averageScore = 0.0;

    scanf("%d", &N);

    ss students[N];

    for(i = 0; i < N; i++) {
        scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name);
        totalScore += students[i].score;
    }

    averageScore = totalScore / N;

    printf("Average Score: %.2f", averageScore);

    return 0;
}