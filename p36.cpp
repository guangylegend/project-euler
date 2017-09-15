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

int ks[30];

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
    memset(ks,0,sizeof(ks));
    for(int i=0;i<=w-1;i++)
    {
        ks[i]=((x-x%pow(10,i))/pow(10,i))%10;
    }
    for(int i=0;i<=w/2-1;i++)
    {
        if(ks[i]!=ks[w-1-i])return false;
    }
    w=1;
    while((x%pow(2,w))!=x)w++;
    memset(ks,0,sizeof(ks));
    for(int i=0;i<=w-1;i++)
    {
        ks[i]=((x-x%pow(2,i))/pow(2,i))%2;
    }
    for(int i=0;i<=w/2-1;i++)
    {
        if(ks[i]!=ks[w-1-i])return false;
    }
    return true;



}

int main()
{
    int sum=0;
    for(int i=1;i<1000000;i++)
    {
        if(test(i))
        {
            sum+=i;
            //cout<<i<<endl;
        }
    }
    cout<<sum<<endl;
}
