#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int f[10000005];
int biaoji[10000005];
int ks[15];
int ks1[15];

void shai(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            for(int j=1;j<=x/i;j++)biaoji[j*i]=i;
        }
    }
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
    int w=1;
    int w1=1;
    while((x%pow(10,w))!=x)w++;
    while((y%pow(10,w1))!=y)w1++;
    if(w!=w1)return false;
    for(int i=0;i<=w-1;i++)
    {
        ks[((x-x%pow(10,i))/pow(10,i))%10]++;
    }
    for(int i=0;i<=w1-1;i++)
    {
        ks1[((y-y%pow(10,i))/pow(10,i))%10]++;
    }
    for(int i=0;i<=9;i++)
    {
        if(ks[i]!=ks1[i])return false;
    }
    return true;
}

int main()
{
    double ans=10000000;
    int ii=0;
    memset(biaoji,0,sizeof(biaoji));
    memset(f,0,sizeof(f));
    shai(10000000);
    f[1]=1;
    for(int i=2;i<10000000;i++)
    {
        int phi=0;
        if(i/biaoji[i]%biaoji[i]==0)phi=f[i/biaoji[i]]*biaoji[i];
        else phi=f[i/biaoji[i]]*(biaoji[i]-1);
        f[i]=phi;
        if((double)(i)/phi<ans)
        {
            if(test(i,phi))
            {
                ans=(double)(i)/phi;
                ii=i;
            }
        }
        if(i%1000000==0)cout<<i<<endl;
    }
    cout<<ii<<endl;
}
