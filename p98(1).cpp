#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<cstring>

using namespace std;
int a[20];
int b[20];

void test(int i,int j)
{
    int s=i;
    int ss=j;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(i!=0)
    {
        if(a[i%10]==1)return;
        if(a[i%10]==0)a[i%10]=1;
        i/=10;
    }
    while(j!=0)
    {
        if(b[j%10]==1)return;
        if(b[j%10]==0)b[j%10]=1;
        j/=10;
    }
    for(int k=0;k<=9;k++)
    {
        if(a[k]!=b[k])return;
    }
    cout<<s<<' '<<ss<<endl;
}

int main()
{
    for(int i=32;i<=316;i++)
    {
        for(int j=i+1;j<=316;j++)
        {
            test(i*i,j*j);
        }
    }
}
