#include<iostream>
using namespace std;

long long int f[60][3];

int main()
{
    long long int sum = 0;
    f[0][0] = 0;
    f[1][0] = 0;
    f[0][1] = 0;
    f[1][1] = 0;
    f[2][1] = 0;
    f[0][2] = 0;
    f[1][2] = 0;
    f[2][2] = 0;
    f[3][2] = 0;
    for(int i=2;i<=50;i++)
    {
        f[i][0] = f[i-2][0] + f[i-1][0] + 1;
    }

    for(int i=3;i<=50;i++)
    {
        f[i][1] = f[i-3][1] + f[i-1][1] + 1;
    }

    for(int i=4;i<=50;i++)
    {
        f[i][2] = f[i-4][2] + f[i-1][2] + 1;
    }
    cout<<f[50][0]+f[50][1]+f[50][2]<<endl;
}
