#include<iostream>
#include<cstring>
using namespace std;

int s[1000005];
int p[1000000];

int main()
{
    memset(p,0,sizeof(p));
    memset(s,0,sizeof(s));
    int scnt=0;
    for(int i=2;i<=1000000;i++)
    {
        if(s[i]==0)
        {
            p[scnt]=i;
            scnt++;
            for(int j=1;j<=1e6/i;j++)s[j*i]=1;
        }
    }
    for(int i=0;i<scnt;i++)
    {
        if(i%2==1)continue;
        long long int a = p[i];
        if(a*(i+1)*2>1e10)
        {
            cout<<i+1<<endl;
            break;
        }
    }
}
