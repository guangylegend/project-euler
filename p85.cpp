#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int calc(int x,int y)
{
    return x*x*y*y+x*x*y+y*y*x+x*y-3*(x+1)*x*(y+1)*y/4;
}

int main()
{
    int min=10000;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(abs(calc(i,j)-2000000)<min)
            {
                min=abs(calc(i,j)-2000000);
                cout<<i*j<<endl;
            }
        }
    }
    //cout<<max<<endl;
}
