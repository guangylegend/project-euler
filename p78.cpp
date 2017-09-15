#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

long long int f[100005];

int main()
{
    memset(f,0,sizeof(f));
    f[0]=1;
    for(int i=1;i<=60000;i++)
    {
        for(int j=1;j<=60000;j++)
        {
            if(j-i>=0)
            {
                f[j]=(f[j-i]+f[j])%1000000;
            }
        }
    }
    for(int i=1;i<=100000;i++)
    {
        if(f[i]==0)
        {
            cout<<i<<endl;
            break;
        }
    }
}
