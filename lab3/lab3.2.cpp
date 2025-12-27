#include <stdio.h>

struct student{

    char name[50];

    int studentId;

    float score;

} typedef SS ;

int main(){

    int N, i;

    if(scanf("%d", &N) != 1){

        return 1;
    }

    SS students[N];

    for(i = 0; i < N; i++){

        if(scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name) != 3){

            return 1;
        }

    }

    for(i = 0; i < N; i++){
        
        printf("id:%d, name:%s, score: %.2f\n", students[i].studentId, students[i].name, students[i].score );

    }


    return 0;
}