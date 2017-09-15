#include<iostream>
#include<cmath>

using namespace std;
int f[70];

int main()
{
    for(int i=1;i<=20;i++)f[i]=i;
    f[21]=25;
    for(int i=22;i<=41;i++)f[i]=2*(i-21);
    f[42]=50;
    for(int i=43;i<=62;i++)f[i]=3*(i-42);

    int ans = 21;

    int tmp = 0;
    for(int i=22;i<=42;i++)
    {
        for(int j=1;j<=62;j++)
        {
            if(f[j]+f[i]<100)ans++;
        }
    }

    for(int i=22;i<=42;i++)
    {
        for(int j=1;j<=62;j++)
        {
            if(2*f[j]+f[i]<100)ans++;
        }
    }

    for(int i=22;i<=42;i++)
    {
        for(int j=1;j<=62;j++)
        {
            for(int k=1;k<=62;k++)
            {
                if(j!=k&&f[k]+f[j]+f[i]<100)tmp++;
            }
        }
    }
    cout<<tmp/2+ans<<endl;
}
