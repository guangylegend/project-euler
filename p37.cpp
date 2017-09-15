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
    if(x==1)return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

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
    int tmp=x;
    for(int i=0;i<=w-1;i++)
    {
        if(!isprime(tmp))return false;
        tmp=(tmp-((tmp-tmp%pow(10,0))/pow(10,0))%10)/10;
    }
    tmp=x;
    for(int i=w-1;i>=0;i--)
    {
        if(!isprime(tmp))return false;
        tmp=tmp-(((tmp-tmp%pow(10,i))/pow(10,i))%10)*pow(10,i);
    }
    return true;


}


int main()
{
    int sum=0;
    for(int i=11;i<10000000;i++)
    {
        if(test(i))
        {
            sum+=i;
            cout<<i<<endl;
        }
    }
    cout<<sum<<endl;
}
