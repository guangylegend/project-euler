#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[15];
int biaoji[15];
int flag=0;
int order[]={9,8,7,6,5,4,3,2,1,10};
int fuckorder[]={1,2,3,4,3,5,6,5,7,8,7,9,10,9,2};
long long int tans=0;

long long int pow(int y,int x)
{
    long long int ans=1;
    while(x--)ans=ans*y;
    return ans;
}

void dfs(int i)
{
    for(int j=0;j<=9;j++)
    {
        if(biaoji[order[j]]==0)
        {
            if(j==9)flag=i;
            ks[i]=order[j];
            biaoji[order[j]]=1;
            if(i==10)
            {
                int sum=ks[1]+ks[2]+ks[3];
                if(ks[3]+ks[4]+ks[5]==sum&&ks[5]+ks[6]+ks[7]==sum&&ks[7]+ks[8]+ks[9]==sum&&ks[2]+ks[9]+ks[10]==sum&&flag!=3&&flag!=5&&flag!=7&&flag!=9&&flag!=2)
                {
                    long long int tsum=0;
                    for(int k=0;k<=14;k++)
                    {
                        if(fuckorder[k]==flag)tsum*=10;
                        tsum+=ks[fuckorder[k]]*pow(10,14-k);
                    }


                    cout<<tsum<<endl;

                    if(tsum>tans)tans=tsum;
                }

            }
            else dfs(i+1);
            biaoji[order[j]]=0;
        }
    }
}

int main()
{
    memset(biaoji,0,sizeof(biaoji));
    memset(ks,0,sizeof(ks));
    dfs(1);
    cout<<tans<<endl;
}
