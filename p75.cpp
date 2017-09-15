#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

bool test(int x)
{
    int cnt=0;
    for(int i=1;i<x/3;i++)
    {
        if(((x-i)*(x-i)-i*i)%(2*(x-i))==0)cnt++;
        if(cnt>=2)return false;
    }
    if(cnt==1)return true;
    return false;

}

int main()
{
    int cnt=0;
    for(int i=1;i<=1500000;i++)
    {
        if(i%10000==0)cout<<i<<endl;
        if(test(i))cnt++;
    }
    cout<<cnt<<endl;
}
