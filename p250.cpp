#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;


long long int rem[300];
long long int remtmp[300];


int re(int x)
{
    int sum=1;
    int k=x;
    while(k--)
    {
        sum=(sum*x)%250;
    }
    return sum;
}

int main()
{
    memset(rem,0,sizeof(rem));
    rem[0]=1;
    for(int i=1;i<=250250;i++)
    {
        memset(remtmp,0,sizeof(remtmp));
        int tmp=re(i);
        for(int j=0;j<=249;j++)remtmp[j]=rem[j-tmp>=0?j-tmp:j+250-tmp];
        for(int j=0;j<=249;j++)rem[j]=(remtmp[j]+rem[j])%10000000000000000;
        cout<<i<<endl;
    }
    cout<<rem[0]-1<<endl;
}
