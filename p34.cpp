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


int jie(int x)
{
    int ans=1;
    while(x>0)
    {
        ans=ans*x;
        x--;
    }
    return ans;
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
    int sum=0;
    for(int i=0;i<=w-1;i++)
    {
        sum+=jie(((x-x%pow(10,i))/pow(10,i))%10);

    }
    if(sum==x)return true;
    return false;


}


int main()
{
    int sum=0;
    for(int i=3;i<10000000;i++)
    {
        if(test(i))
        {
            sum+=i;
            cout<<i<<endl;
        }
    }
    cout<<sum<<endl;
}
