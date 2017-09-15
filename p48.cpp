#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

long long int calc(int x)
{
    long long int tmp=1;
    for(int i=1;i<=x;i++)
    {
        tmp=(tmp*x)%10000000000;
    }
    return tmp;
}

long long int add(long long int a,long long int b)
{
    return (a+b)%10000000000;
}


int main()
{
    long long int sum=0;
    for(int i=1;i<=1000;i++)
    {
        long long int tmp=calc(i);
        sum=add(sum,tmp);
    }
    cout<<sum<<endl;
}
