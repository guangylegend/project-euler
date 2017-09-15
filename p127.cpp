#include"mymath.h"
#include<set>
#define maxn 120000
long long int rad[150000];

int main()
{
    int sum = 0;
    for(int i=1;i<=maxn;i++)
    {
        rad[i] = 1;
    }
    for(int i=2;i<=maxn;i++)
    {
        if(rad[i]==1)
        {
            for(int j=1;j*i<=maxn;j++)rad[j*i]*=i;
        }
    }
    for(int c=1;c<maxn;c++)
    {
        if(rad[c]<c)
        {
            int lim = c/rad[c];
            for(int a=1;a<c/2;a++)
            {
                if(rad[a]*rad[c-a]<lim)
                {
                    if(reprime(a,c))sum+=c;//cout<<c<<endl;
                }
            }
        }
    }
    cout<<sum<<endl;
}
