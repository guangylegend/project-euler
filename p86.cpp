#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int f[10005];

bool test(int x,int y,int z)
{
    int tmp=(x+y)*(x+y)+z*z;
    if(fabs(int(sqrt(tmp))-sqrt(tmp))<1e-8)return true;
    return false;
}

void calc(int x)
{
    int cnt=0;
    for(int i=1;i<x;i++)
    {
        for(int j=i;j<x;j++)
        {
            if(test(i,j,x))cnt++;
        }
    }
    for(int i=1;i<x;i++)
    {
        if(test(i,x,x))cnt++;
    }
    f[x]=f[x-1]+cnt;
}

int main()
{
    memset(f,0,sizeof(f));
    f[0]=0;
    for(int i=1;i<=10000;i++)
    {
        calc(i);
        if(f[i]>1000000)
        {
            cout<<i<<endl;
            break;
        }
    }
}
