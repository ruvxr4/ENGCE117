#include <stdio.h>

int main(){

    int N, i;

    int countfizzbuzz = 0, countfizz = 0, countbuzz = 0, countother = 0;

    if (scanf("%d", &N) != 1) {

        return 1;
    }

    for (i = 1; i <= N; i++) {

        if (i % 15 == 0) {

            countfizzbuzz++;

        } else if (i % 3 == 0) {

            countfizz++;

        } else if (i % 5 == 0) {

            countbuzz++;

        } else {

            countother++;
        }
    }

    printf("Count FizzBuzz(by 15): %d\n", countfizzbuzz);

    printf("Count Fizz(by 3 only): %d\n", countfizz);

    printf("Count Buzz(by 5 only): %d\n", countbuzz);
    
    printf("Count Other: %d\n", countother);

    return 0;
}