#include<iostream>

using namespace std;

long long int f[100];

int main()
{
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    f[4] = 8;
    for(int i=5;i<=50;i++)f[i] = f[i-1]+f[i-2]+f[i-3]+f[i-4];
    cout<<f[50]<<endl;
}
