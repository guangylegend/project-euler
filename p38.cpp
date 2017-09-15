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

int ks[15];
int cnt=1;

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
    for(int i=w-1;i>=0;i--)
    {
        if(((x-x%pow(10,i))/pow(10,i))%10==0)return false;
        if(ks[((x-x%pow(10,i))/pow(10,i))%10]==0)
        {
            ks[((x-x%pow(10,i))/pow(10,i))%10]=cnt;
            cnt++;
        }
        else return false;
    }
    return true;


}

bool isproperty(int x)
{
    memset(ks,0,sizeof(ks));
    cnt=1;
    int i=1;
    while(test(x*i))
    {
        bool flag=true;
        for(int j=1;j<=9;j++)
        {
            if(ks[j]==0)flag=false;
        }
        if(flag==true)return true;
        i++;
    }
    return false;
}

int main()
{
    int max=0;
    for(int i=1;i<10000;i++)
    {
        if(isproperty(i))
        {
            int sum=0;
            for(int j=1;j<=9;j++)
            {
                sum+=j*pow(10,9-ks[j]);
            }
            if(sum>max)max=sum;
        }
    }
    cout<<max<<endl;
}
