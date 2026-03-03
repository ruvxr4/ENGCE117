#include <stdio.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx ) ;

int main() {
    
    int n = 5, wx = 11 ;

    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;

    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    
    int *x = KnapsackGreedy( w, v, n, wx ) ;
    
    for( int i = 0 ; i < n ; i++ ) {

        printf( "%d ", x[ i ] ) ;

    } // end for
    
    return 0 ;

} // end main

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {

    int *x = new int[ n ] ;

    int *visited = new int[ n ] ;

    int weight = 0 ;

    int i, j, best_i ;

    double max_ratio ;

    for( i = 0 ; i < n ; i++ ) {

        x[ i ] = 0 ;

        visited[ i ] = 0 ;

    } // end for

    while( weight < wx ) {

        best_i = -1 ;

        max_ratio = -1.0 ;

        for( j = 0 ; j < n ; j++ ) {

            if( visited[ j ] == 0 ) {

                double ratio = (double)v[ j ] / w[ j ] ;

                if( ratio > max_ratio ) {

                    max_ratio = ratio ;

                    best_i = j ;

                } // end if

            } // end if

        } // end for

        if( best_i == -1 ) {

            break ; 

        } // end if

        if( weight + w[ best_i ] <= wx ) {

            x[ best_i ] = 1 ;

            weight += w[ best_i ] ;

        } // end if
        
        visited[ best_i ] = 1 ; 

    } // end while

    return x ;

} // end KnapsackGreedy