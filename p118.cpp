#include"mymath.h"
using namespace std;

int func( int *v, int k, int n, int d ) {
    int i, s = 0, p = isprime( n );

    if( k == 9 ) return p;
    for( i = 1; i <= 9; ++i ) {
        if( !v[i] ) { v[i] = 1;  s += func( v, k+1, 10*n+i, d ); v[i] = 0; }
    }
    if( !p ) return s;
    for( i = d+1; i <= 9; ++i ) {
        if( !v[i] ) { v[i] = 1; s += func( v, k+1, i, i ); v[i] = 0; }
    }
    return s;
}

int main() {
    int i, s = 0, v[ 10 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for( i = 1; i <= 9; ++i ){
        v[i] = 1; s += func( v, 1, i, i ); v[i] = 0;
    }
    printf( "%d\n", s );
    return 0;
}




