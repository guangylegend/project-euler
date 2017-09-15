#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int prime[1000005];
int s[2000005];
int pn = 0;

int check(int n)
{
    int cnt = 1;
    int rem = 1;
    int ans = 0;
    while(1)
    {
        ans=(ans+rem)%n;
        if(ans!=0)
        {
            cnt++;
            rem = rem*10%n;
        }
        else return cnt;
    }
}

int main()
{
    int sum = 0;
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


    int cnt = 0;
    for(int i=0;i<pn-1;i++)
    {
        if(cnt==40)break;
        if(prime[i]==5||prime[i]==2)continue;
        long long int k = 1000000000;
        if(k%check(prime[i])==0)
        {
            cnt++;
            sum+=prime[i];
        }
        cout<<cnt<<endl;
    }
    cout<<sum<<endl;

}
