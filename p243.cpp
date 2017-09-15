#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<math.h>

using namespace std;


int prime[] = {2,3,5,7,11,13,17,19,23,29,31};

int main()
{
    /*for(int i=0;i<=10;i++)
    {
        int d = 1;
        for(int j=0;j<=i;j++)
        {
            d*=prime[j];
        }
        int fi = 1;
        for(int j=0;j<=i;j++)
        {
            fi*=(prime[j]-1);
        }
        if((fi+0.0)/(d-1)<(15499+0.0)/94744)
        {
            cout<<prime[i]<<endl;
            break;
        }
    }*/
    long long int base = 1;
    long long int fi = 1;
    for(int i=0;i<9;i++)
    {
        base*=prime[i];
    }
    for(int i=0;i<9;i++)
    {
        fi*=(prime[i]-1);
    }
    long long int limit = base*29;
    for(int i=0;i<9;i++)
    {
        for(int j=1;;j++)
        {
            int tmp = pow(prime[i],j);
            if(tmp>29)break;
            if((fi*tmp+0.0)/(tmp*base-1)<(15499+0.0)/94744 && tmp*base<limit)limit=tmp*base;
        }
    }
    cout<<limit<<endl;
}
