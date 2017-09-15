#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


int p[2000005];
int biaoji[2000005];
long long int f[2000005];
long long int ftmp[2000005];
int tot=0;
int stot=0;

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

void sha(int x)
{
    memset(biaoji,0,sizeof(biaoji));
    int cnt=1;
    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            if(i>5000&&tot==0)tot=cnt-1;
            if(i<5000)stot+=i;
            p[cnt]=i;
            cnt++;
            for(int j=2;j<=x/i;j++)biaoji[j*i]=1;
            biaoji[i]=2;
        }
    }
}

int main()
{
    long long int sum=0;
    sha(2000000);
    memset(f,0,sizeof(f));
    f[0]=1;
    for(int i=1;i<=tot;i++)
    {
        memset(ftmp,0,sizeof(ftmp));
        for(int j=0;j<=stot-p[i];j++)
        {
            if(f[j]!=0)ftmp[j+p[i]]=f[j];
        }
        for(int j=0;j<=stot;j++)
        {
            f[j]=(ftmp[j]+f[j])%10000000000000000;
        }
    }
    for(int i=2;i<=stot;i++)
    {
        if(biaoji[i]==2)sum=(sum+f[i])%10000000000000000;
    }
    cout<<sum<<endl;
}
