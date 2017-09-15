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
    for(int i=0;i<=90;i++)
    {
        for(int j=0;j<=90;j++)
        {
            f[i][j]=1000000;
        }
    }

    f[1][1]=ks[1][1];

    for(int i=2;i<=159;i++)
    {
        for(int j=1;j<=(i>80?160-i:i);j++)
        {
            int ki=(i>80?80-j+1:i-j+1);
            int kj=(i>80?i-80+j:j);
            if(kj==1)f[ki][kj]=ks[ki][kj]+f[ki-1][kj];
            else if(ki==1)f[ki][kj]=ks[ki][kj]+f[ki][kj-1];
            else f[ki][kj]=ks[ki][kj]+min(f[ki-1][kj],f[ki][kj-1]);

        }

    }
    bool flag=false;
    while(flag==false)
    {
        flag=true;
        for(int i=2;i<=159;i++)
        {
            for(int j=1;j<=(i>80?160-i:i);j++)
            {
                int ki=(i>80?80-j+1:i-j+1);
                int kj=(i>80?i-80+j:j);
                if(f[ki-1][kj]+ks[ki][kj]<f[ki][kj])
                {
                    f[ki][kj]=f[ki-1][kj]+ks[ki][kj];
                    flag=false;
                }
                if(f[ki+1][kj]+ks[ki][kj]<f[ki][kj])
                {
                    f[ki][kj]=f[ki+1][kj]+ks[ki][kj];
                    flag=false;
                }
                if(f[ki][kj-1]+ks[ki][kj]<f[ki][kj])
                {
                    f[ki][kj]=f[ki][kj-1]+ks[ki][kj];
                    flag=false;
                }
                if(f[ki][kj+1]+ks[ki][kj]<f[ki][kj])
                {
                    f[ki][kj]=f[ki][kj+1]+ks[ki][kj];
                    flag=false;
                }
            }
        }
    }


    cout<<f[80][80]<<endl;




}
