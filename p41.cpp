#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[15] , p[15] ;
int mark[10];
int tmax=0;

bool isprime(int x)
{
    if(x==1)return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int pow(int y,int x)
{
    int ans=1;
    while(x--)ans=ans*y;
    return ans;
}

void dfs(int i,int n)
{
    for(int j=n;j>=1;j--)
    {
        if(mark[j]==0)
        {
            mark[j]=1;
            ks[i]=j;
            if(i==n)
            {
                int tmp=0;

                for(int k=1;k<=n;k++)tmp+=ks[k]*pow(10,n-k);
                if(isprime(tmp)&&tmp>tmax)tmax=tmp;
            }
            else dfs(i+1,n);
            mark[j]=0;
        }
    }
}



int main()
{

    for(int i=1;i<=8;i++)
    {
        memset(mark,0,sizeof(mark));
        dfs(1,i);
    }
    cout<<tmax<<endl;


}
