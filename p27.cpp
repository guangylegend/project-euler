#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

bool isprime(int x)
{
    if(x<=1)return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int main()
{
    int max=0;
    int ans=0;
    for(int i=-999;i<1000;i++)
    {
        for(int j=-999;j<1000;j++)
        {
            int cnt=0;
            for(int n=0;;n++)
            {
                if(isprime(n*n+i*n+j))cnt++;
                else break;
            }
            if(cnt>max)
            {
                ans=i*j;
                max=cnt;
            }
        }
    }
    cout<<ans<<' '<<max<<endl;
}
