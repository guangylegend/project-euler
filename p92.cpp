#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[10000001];
int cnt=0;

int test(int x)
{
    if (x==1)return 1;
    if (x==89)return 89;
    int tmp=0;
    if (ks[x]!=0)return ks[x];
    while(x!=0)
    {
        tmp+=(x-(x/10)*10)*(x-(x/10)*10);
        x/=10;
    }
    return test(tmp);

}

int main()
{
    memset(ks,0,sizeof(ks));
    for(int i=1;i<10000000;i++)
    {
        ks[i]=test(i);
        if (ks[i]==89)cnt++;
        if(i%10000==0)cout<<i<<endl;
    }
    cout<<cnt<<endl;
}
