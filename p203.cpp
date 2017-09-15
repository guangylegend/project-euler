#include<iostream>
#include<cmath>
#include<set>
using namespace std;
long long int f[100][100];
set<int> a;
long long int ans=0;

int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main()
{
    a.clear();
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1)f[i][j]=1;
            else if(j==i)f[i][j]=1;
            else f[i][j] = f[i-1][j]+f[i-1][j-1];
            int flag = true;
            for(int k=0;k<=14;k++)
            {
                if(f[i][j]%(p[k]*p[k])==0)
                {
                    flag = false;
                }
            }
            if(flag)
            {
                if(a.count(f[i][j])==0)
                    {
                        a.insert(f[i][j]);
                        ans += f[i][j];
                    }
            }
        }
    }
    cout<<ans<<endl;
}
