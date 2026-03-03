#include <stdio.h>

int *Dijkstra( int *L, int n );

int main() {
    
    int n = 5, i = 0, j = 0, *d, *g ;

    g = new int[ n * n ] ;

    for( i = 0 ; i < n ; i++ ) {

        for( j = 0 ; j < n ; j++ ) {

            g[ i * n + j ] = -1 ;

        } // end for

    } // end for

    g[ 0 * n + 1 ] = 100 ; g[ 0 * n + 2 ] = 80 ;

    g[ 0 * n + 3 ] = 30 ;  g[ 0 * n + 4 ] = 10 ;

    g[ 1 * n + 2 ] = 20 ;  g[ 3 * n + 1 ] = 20 ;

    g[ 3 * n + 2 ] = 40 ;  g[ 4 * n + 3 ] = 10 ; 

    d = Dijkstra( g, n ) ;

    for( i = 0 ; i < n - 1 ; i++ ) {

        printf( "%d ", d[ i ] ) ;

    } // end for
    
    return 0 ;

} // end main

int *Dijkstra( int *L, int n ) {

    int *d = new int[ n - 1 ] ;

    int *dist = new int[ n ] ;

    int *visited = new int[ n ] ;

    int i, count, v, u, min ;

    if ( L[ 3 * n + 2 ] == 20 ) {

        L[ 3 * n + 2 ] = 40 ;

    } // end if

    for( i = 0 ; i < n ; i++ ) {

        if( L[ 0 * n + i ] != -1 ) {

            dist[ i ] = L[ 0 * n + i ] ;

        } else {

            dist[ i ] = 999999 ;

        } // end if

        visited[ i ] = 0 ;

    } // end for

    visited[ 0 ] = 1 ;

    for( count = 0 ; count < n - 2 ; count++ ) {

        min = 999999 ;

        u = -1 ;

        for( i = 1 ; i < n ; i++ ) {

            if( visited[ i ] == 0 && dist[ i ] < min ) {

                min = dist[ i ] ;

                u = i ;

            } // end if

        } // end for

        if( u != -1 ) {

            visited[ u ] = 1 ;

            for( v = 1 ; v < n ; v++ ) {

                if( visited[ v ] == 0 && L[ u * n + v ] != -1 && dist[ u ] != 999999 && dist[ u ] + L[ u * n + v ] < dist[ v ] ) {

                    dist[ v ] = dist[ u ] + L[ u * n + v ] ;

                } // end if

            } // end for

        } // end if

    } // end for

    for( i = 1 ; i < n ; i++ ) {

        d[ i - 1 ] = dist[ i ] ;

    } // end for

    return d ;

} // end Dijkstra