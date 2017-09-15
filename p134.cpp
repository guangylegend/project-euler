#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int prime[1000005];
int s[2000005];
int pn = 0;
long long int ans = 0;

long long int gcd(int m,int n,int mod)
{
    long long int i=1;
    while(1)
    {
        if(m*i%mod!=n)i++;
        else return m*i;
    }
}

int power(int n)
{
    int i = 1;
    while(n--)
    {
        i*=10;
    }
    return i;
}

int digit(int n)
{
    int cnt=0;
    while(n!=0)
    {
        n=n/10;
        cnt++;
    }
    return cnt;
}

void findn(int a,int b)
{
    ans+=gcd(power(digit(a)),b-a,b)+a;
}

int main()
{
    memset(prime,0,sizeof(prime));
    memset(s,0,sizeof(s));
    for(int i=2;i<=2000000;i++)
    {
        if(s[i]==0)
        {
            prime[pn] = i;
            pn++;
            for(int j=2;j<=2000000/i;j++)s[i*j]=1;
        }
    }
    for(int i=0;i<pn-1;i++)
    {
        if(prime[i]>1000000)break;
        if(prime[i]==3||prime[i]==2)continue;
        cout<<i<<endl;
        findn(prime[i],prime[i+1]);
    }
    cout<<ans<<endl;
}
