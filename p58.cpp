#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


int ks[1000005];

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int main()
{
    ks[1]=0;
    for(int i=2;;i++)
    {
        int tsum=1+4*(i-1);
        int tmp=(2*i-1)*(2*i-1);
        int cnt=0;
        if(isprime(tmp-2*(i-1)))cnt++;
        if(isprime(tmp-4*(i-1)))cnt++;
        if(isprime(tmp-6*(i-1)))cnt++;
        ks[i]=ks[i-1]+cnt;
        if(10*ks[i]<tsum)
        {
            cout<<2*i-1<<endl;
            break;
        }
    }
}
