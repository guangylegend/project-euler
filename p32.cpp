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
        if(((x-x%pow(10,i))/pow(10,i))%10==0)return false;
        if(ks[((x-x%pow(10,i))/pow(10,i))%10]==0)ks[((x-x%pow(10,i))/pow(10,i))%10]=1;
        else return false;
    }
    return true;


}

bool isproperty(int x)
{
    for(int i=1;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            memset(ks,0,sizeof(ks));
            if(test(i)&&test(x)&&test(x/i))
            {
                bool flag=false;
                for(int j=1;j<=9;j++)
                {
                    if(ks[j]==0)flag=true;;
                }
                if(flag==false)
                {
                    cout<<i<<' '<<x/i<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int sum=0;
    for(int i=1000;i<10000;i++)
    {
        if(isproperty(i))
        {
            sum+=i;
            cout<<i<<endl;
        }
    }
    cout<<sum<<endl;
}
