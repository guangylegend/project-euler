#include<iostream>
using namespace std;

long long int f[105][15][2];//0 for up,1 for down

int main()
{
    long long int sum = 9;
    for(int i=1;i<=9;i++)f[1][i][0]=f[1][i][1]=1;
    for(int i=2;i<=100;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=j;k++)f[i][j][1]+=f[i-1][k][1];
            sum+=f[i][j][1];
        }
        for(int j=0;j<=9;j++)
        {
            for(int k=j;k<=9;k++)f[i][j][0]+=f[i-1][k][0];
            sum+=f[i][j][0];
        }
        sum-=9;
    }
    cout<<sum<<endl;
}
