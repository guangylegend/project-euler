#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

long long int s[15][15];
long long int tmp[15][15];

int main()
{
    memset(s,0,sizeof(s));
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(i+j<=9)s[i][j]=1;
        }
    }
    for(int k=3;k<=20;k++)
    {
        memset(tmp,0,sizeof(tmp));
            for(int i=0;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    if(i+j<=9)
                    {
                        for(int m=0;m<=9-i-j;m++)
                        {
                            tmp[m][i] += s[i][j];
                        }
                    }
                }
            }
            for(int i=0;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    s[i][j]=tmp[i][j];
                }
            }
    }
    long long int sum = 0;
    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            sum+=s[i][j];
        }
    }
    cout<<sum<<endl;
}
