#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


int p[1000005];
int biaoji[1000005];
long long int sum[1000005];
int cnt=1;

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
    sum[0]=0;
    memset(biaoji,0,sizeof(biaoji));
    cnt=1;
    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            p[cnt]=i;
            sum[cnt]=sum[cnt-1]+i;
            cnt++;
            for(int j=2;j<=x/i;j++)biaoji[j*i]=1;
            biaoji[i]=2;
        }
    }
}




int main()
{
    sha(1000000);
    int ans=0;
    int len=0;
    for(int i=0;i<=cnt-1;i++)
    {
        for(int j=i+1;j<=cnt-1;j++)
        {
            if(sum[j]-sum[i]<1000000)
            {
                if(biaoji[sum[j]-sum[i]]==2&&j-i>len)
                {
                    ans=sum[j]-sum[i];
                    len=j-i;
                }
            }

        }
    }
    cout<<ans<<endl;
}
