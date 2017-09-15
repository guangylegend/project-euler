#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[15];
int mark[10];
long long int tsum=0;
int cks[]={2,3,5,7,11,13,17};

long long int pow(int y,int x)
{
    long long int ans=1;
    while(x--)ans=ans*y;
    return ans;
}

bool isprime(int x)
{
    if(x==1)return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

bool isproperty()
{
    for(int i=0;i<=6;i++)
    {
        int tmp=0;
        for(int k=1;k<=3;k++)tmp+=ks[i+k+1]*pow(10,3-k);
        if(tmp%cks[i]!=0)return false;
    }
    return true;
}




void dfs(int i,int n)
{
    for(int j=n-1;j>=0;j--)
    {
        if(mark[j]==0)
        {
            mark[j]=1;
            ks[i]=j;
            if(i==n)
            {
                if(ks[1]!=0&&isproperty())
                {
                    long long int tmp=0;
                    for(int k=1;k<=n;k++)tmp+=ks[k]*pow(10,n-k);
                    cout<<tmp<<endl;
                    tsum+=tmp;
                }

            }
            else dfs(i+1,n);
            mark[j]=0;
        }
    }
}



int main()
{
    memset(mark,0,sizeof(mark));
    dfs(1,10);
    cout<<tsum<<endl;
}
