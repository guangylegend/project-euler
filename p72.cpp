#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int f[1000005];
int biaoji[1000005];

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

int main()
{
    long long int ans=0;
    memset(biaoji,0,sizeof(biaoji));
    memset(f,0,sizeof(f));
    shai(1000005);
    f[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        int phi=0;
        if(i/biaoji[i]%biaoji[i]==0)phi=f[i/biaoji[i]]*biaoji[i];
        else phi=f[i/biaoji[i]]*(biaoji[i]-1);
        f[i]=phi;
    }
    for(int i=2;i<=1000000;i++)
    {
        ans+=f[i];
    }
    cout<<ans<<endl;
}
