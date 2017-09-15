#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<map>
#include<set>
#include"assert.h"

using namespace std;

int isprime(int n)
{
  int i;
  if( n < 2 ) return 0;
  if( ! ( n&1 ) ) return n == 2;
  for( i = 3; i*i <= n; i += 2 ) if( !( n%i ) ) return 0;
  return 1;
}

int factorial(int n)
{
    if( n == 1 ) return 1;
    else return n * factorial ( n-1 );
}

int gcd(int a,int b)
{
    while(b)
    {
        int c = b;
        b = a%b;
        a = c;
    }
    return a;
}

bool reprime(int a,int b)
{
    return gcd(a,b)==1;
}

long long int mypow(int n,int m)  //fast power?
{
    long long int ans = 1;
    while(m--)
    {
        ans*=n;
    }
    return ans;
}
