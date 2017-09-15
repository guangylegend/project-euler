#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int f[100][100];
int ks[100][100];

int main()
{
    freopen("in.txt","r",stdin);
    memset(ks,0,sizeof(ks));
    memset(f,0,sizeof(f));

    for(int i=1;i<=80;i++)
    {
        for(int j=1;j<=80;j++)
        {
            scanf("%d",&ks[i][j]);
        }
    }
    for(int i=1;i<=80;i++)
    {
        f[i][1]=ks[i][1];
    }
    for(int j=2;j<=80;j++)
    {
        for(int k=1;k<=80;k++)f[k][j]=ks[k][j]+f[k][j-1];
        bool flag=false;
        while(flag==false)
        {
            flag=true;
            for(int i=1;i<=80;i++)
            {
                if(i==1)
                {
                    if(f[2][j]+ks[1][j]<f[1][j])
                    {
                        f[1][j]=f[2][j]+ks[1][j];
                        flag=false;
                    }
                }
                else if(i==80)
                {
                    if(f[79][j]+ks[80][j]<f[80][j])
                    {
                        f[80][j]=f[79][j]+ks[80][j];
                        flag=false;
                    }
                }
                else
                {
                    if(f[i-1][j]+ks[i][j]<f[i][j])
                    {
                        f[i][j]=f[i-1][j]+ks[i][j];
                        flag=false;
                    }
                    if(f[i+1][j]+ks[i][j]<f[i][j])
                    {
                        f[i][j]=f[i+1][j]+ks[i][j];
                        flag=false;
                    }
                }
            }
        }
    }
    int ans=100000000;
    for(int i=1;i<=80;i++)
    {
        ans=min(ans,f[i][80]);
    }
    cout<<ans<<endl;


}
