#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int x=1;
    int y=3;
    int cnt=0;
    while(1)
    {
        if(y==2)break;
        for(int b=12000;b>=2;b--)
        {
            if((b*x+1)%y==0)
            {
                x=(b*x+1)/y;
                y=b;
                break;
            }
        }
        cnt++;
    }
    cout<<cnt-1<<endl;
}
