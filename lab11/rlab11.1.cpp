#include <stdio.h>

int BinSearch(int data[], int n, int find);

int main() {

    int data[6] = {1, 2, 3, 4, 5, 7};

    int n = 6, find = 5;

    int pos = BinSearch(data, n, find);

    printf("Found %d at %d\n", find, pos);

    return 0;

} // end main

int BinSearch(int data[], int n, int find) {

    int i = 0, j = n - 1, m;
    
    while (i <= j) {

        m = (i + j) / 2;
        
        if (data[m] == find) {

            return m;

        } else if (data[m] < find) {

            i = m + 1;

        } else {

            j = m - 1;

        } // end if

    } // end while
    
    return -1;
    
} // end BinSearch