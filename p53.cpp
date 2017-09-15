#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#define n 100
using namespace std;

int ks[1005][1005];

int main()
{
    ks[0][0]=1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)ks[i][j]=1;
            else if(j==i)ks[i][j]=1;
            else
            {
                if(ks[i-1][j-1]==-1||ks[i-1][j]==-1)
                {
                    ks[i][j]=-1;
                    cnt++;
                }
                else
                {
                    ks[i][j]=ks[i-1][j-1]+ks[i-1][j];
                    if(ks[i][j]>1000000)
                    {
                        ks[i][j]=-1;
                        cnt++;
                    }
                }
            }
        }
    }

    cout<<cnt<<endl;
}
