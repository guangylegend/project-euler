#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int rem[1005];

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int ks[15];

int pow(int y,int x)
{
    int ans=1;
    while(x--)ans=ans*y;
    return ans;
}

bool test(int x)
{
    int w=1;
    while((x%pow(10,w))!=x)w++;
    for(int i=0;i<=w-1;i++)
    {
        ks[i]=((x-x%pow(10,i))/pow(10,i))%10;
    }
    int sum=0;
    for(int i=0;i<=w-1;i++)sum+=ks[i]*pow(10,i);
    if(!isprime(sum))return false;
    for(int i=1;i<=w-1;i++)
    {
        int tmp=ks[0];
        for(int i=0;i<w-1;i++)ks[i]=ks[i+1];
        ks[w-1]=tmp;
        sum=0;
        for(int i=0;i<=w-1;i++)sum+=ks[i]*pow(10,i);
        if(!isprime(sum))return false;
    }
    return true;



}

int main()
{
    int sum=0;
    for(int i=2;i<1000000;i++)
    {
        if(test(i))
        {
            sum++;
            cout<<i<<endl;
        }
    }
    cout<<sum<<endl;
}
