#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int p2[10005];
int p3[10005];
int p4[10005];
int biaoji[10005];
int cnt2=0;
int cnt3=0;
int cnt4=0;
bool flag3=false;
bool flag4=false;
int kai[55000005];

void sha(int x)
{
    memset(biaoji,0,sizeof(biaoji));
    cnt2=0;
    cnt3=0;
    cnt4=0;
    for(int i=2;i<=x;i++)
    {
        if(biaoji[i]==0)
        {
            if(i*i>55000000)break;
            if(i*i*i>55000000)flag3=true;
            if(i*i*i*i>55000000)flag4=true;
            cnt2++;
            p2[cnt2]=i*i;

            if(i*i*i<55000000&&!flag3)
            {
                cnt3++;
                p3[cnt3]=i*i*i;
            }
            if(i*i*i*i<55000000&&!flag4)
            {
                cnt4++;
                p4[cnt4]=i*i*i*i;
            }

            for(int j=2;j<=x/i;j++)
            {
                if(biaoji[i*j]==0)biaoji[j*i]=1;
            }
            biaoji[i]=2;
        }
    }
}

int main()
{
    int cnt=0;
    sha(10000);

    for(int i=1;i<=cnt2;i++)
    {
        for(int j=1;j<=cnt3;j++)
        {
            for(int k=1;k<=cnt4;k++)
            {
                if(p2[i]+p3[j]+p4[k]<50000001)
                {
                    kai[p2[i]+p3[j]+p4[k]]=1;
                }
            }
        }
    }
    for(int i=1;i<=50000000;i++)if(kai[i]==1)cnt++;
    cout<<cnt<<endl;
}
