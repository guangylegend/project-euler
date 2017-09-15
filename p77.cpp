#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int p[10005];
int biaoji[10005];
int f[10005];
int cnt=0;

void shai(int x)
{
    memset(biaoji,0,sizeof(biaoji));

    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            cnt++;
            p[cnt]=i;
            for(int j=2;j<=x/i;j++)biaoji[j*i]=1;
            biaoji[i]=2;
        }
    }
}


int main()
{
    memset(f,0,sizeof(f));
    memset(p,0,sizeof(p));
    memset(biaoji,0,sizeof(biaoji));
    shai(1000);
    f[0]=1;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(j-p[i]>=0)
            {
                f[j]+=f[j-p[i]];
            }
        }
    }
    for(int i=1;i<=10000;i++)
    {
        if(f[i]>5000)
        {
            cout<<i<<endl;
            break;
        }
    }
}
