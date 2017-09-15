#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int f[1005][1005];

int main()
{
    memset(f,0,sizeof(f));
    for(int i=0;i<=1000;i++)
    {
        f[i][1]=1;
    }
    for(int i=2;i<=10;i++)
    {
        int cnt=0;
        for(int j=2;j<=i;j++)
        {
            if(f[i][j]==0)f[i][j]=f[i-1][j-1]+f[i-j][j];
            cnt+=f[i][j];
        }
        cout<<cnt+1<<endl;
    }
}
