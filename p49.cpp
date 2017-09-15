#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


int p[1000005];
int biaoji[1000005];
int cnt=1;
int ks[15],ks1[15];

bool isprime(int x)
{
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

bool test(int x,int y)
{
    memset(ks,0,sizeof(ks));
    memset(ks1,0,sizeof(ks1));
    for(int i=3;i>=0;i--)
    {
        ks[((x-x%pow(10,i))/pow(10,i))%10]++;
    }
    for(int i=3;i>=0;i--)
    {
        ks1[((y-y%pow(10,i))/pow(10,i))%10]++;
    }
    for(int i=0;i<=9;i++)
    {
        if(ks[i]!=ks1[i])return false;
    }
    return true;


}

void sha(int x)
{
    memset(biaoji,0,sizeof(biaoji));
    cnt=1;
    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            if(i>1000)
            {
                p[cnt]=i;
                cnt++;
            }

            for(int j=2;j<=x/i;j++)biaoji[j*i]=1;
            biaoji[i]=2;
        }
    }
}

int main()
{
    sha(10000);
    for(int i=1;i<=cnt-1;i++)
    {
        for(int j=i+1;j<=cnt-1;j++)
        {
            if(test(p[i],p[j]))
            {
                int tmp=2*p[j]-p[i];
                if(tmp>10000)continue;
                if(test(p[i],tmp)&&biaoji[tmp]==2)
                {
                    cout<<p[i]<<p[j]<<tmp<<endl;
                }
            }
        }
    }
}
