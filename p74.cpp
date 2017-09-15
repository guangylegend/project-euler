#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int cycle[100];

int ks[1000005];

int ans=0;
int jie[]={1,1,2,6,24,120,720,5040,40320,362880};

int calc(int x)
{
    int tmp=0;
    while(x!=0)
    {
        tmp+=jie[x-(x/10)*10];
        x/=10;
    }
    return tmp;
}

void test(int i)
{
    memset(cycle,0,sizeof(cycle));
    int cnt=0;
    int tmp=i;
    cycle[0]=i;
    while(1)
    {
        cnt++;
        tmp=calc(tmp);

        for(int j=0;j<=cnt-1;j++)
        {
            if(cycle[j]==tmp)
            {
                ks[i]=cnt;
                if(ks[i]==60)ans++;
                return;
            }
        }
        cycle[cnt]=tmp;

    }
}

int main()
{
    memset(ks,0,sizeof(ks));
    for(int i=1;i<=1000000;i++)
    {
        if(i%10000==0)cout<<i<<endl;
        test(i);
    }
    cout<<ks[69]<<endl;
    cout<<ans<<endl;
}
