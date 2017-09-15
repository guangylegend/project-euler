#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int line=1;
    int base=0;
    int exp=0;
    scanf("%d %d",&base,&exp);
    for(int i=2;i<=1000;i++)
    {
        int tmp1,tmp2;
        scanf("%d %d",&tmp1,&tmp2);
        if(tmp1>pow(base,(exp+0.0)/tmp2))
        {
            line=i;
            base=tmp1;
            exp=tmp2;
        }
    }
    cout<<line<<endl;
}
