#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int rem[1005];

int main()
{
    int max=0;
    int maxi=0;
    for(int i=1;i<1000;i++)
    {
        memset(rem,0,sizeof(rem));
        int tmp=1;
        int cnt=0;
        while(1)
        {
            tmp*=10;
            tmp=tmp%i;
            if(tmp==0)
            {
                cnt=0;
                break;
            }
            if(rem[tmp]==0)
            {
                rem[tmp]=cnt;
                cnt++;
            }
            else
            {
                cnt=cnt-rem[tmp];

                break;
            }
        }
        if(cnt>max)maxi=i;
    }
    cout<<maxi<<endl;
}

