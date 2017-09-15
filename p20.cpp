#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int ks[10005];

int main()
{
    for(int i=1;i<=10000;i++)ks[i]=0;
    ks[1]=1;
    int len=1;
    for(int i=2;i<=100;i++)
    {
        int tmp=0;
        int t=len;
        for(int j=1;j<=t+3;j++)
        {
            int ttmp=ks[j]*i+tmp;
            if((ttmp==0)&&(j>t))
            {
                len=j-1;
                break;
            }
            tmp=(ttmp-ttmp%10)/10;
            ks[j]=ttmp%10;
        }
    }
    int tsum=0;
    for(int i=1;i<=10000;i++)tsum+=ks[i];
    cout<<tsum<<endl;
}
