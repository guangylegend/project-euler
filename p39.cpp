#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int ks[30];

int pow(int y,int x)
{
    int ans=1;
    while(x--)ans=ans*y;
    return ans;
}

int test(int x)
{
    int cnt=0;
    for(int i=1;i<=x/3;i++)
    {
        for(int j=i;j<=(x-i)/2;j++)
        {
            if(i*i+j*j==(x-i-j)*(x-i-j))cnt++;
        }
    }
    return cnt;
}

int main()
{
    int max=0;
    int maxi=0;
    for(int i=1;i<1000;i++)
    {
        int tmp = test(i);
        if(tmp>max)
        {
            max=tmp;
            maxi=i;
        }
    }
    cout<<maxi<<endl;
}
