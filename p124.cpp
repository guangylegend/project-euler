#include<iostream>
#include<algorithm>
using namespace std;

struct s
{
    int n;
    int e;
}a[100005];
bool cmp(s x,s y)
{
    if(x.e>y.e)return false;
    else if(x.e==y.e)return x.n<y.n;
    return true;
}



int main()
{
    for(int i=1;i<=100000;i++)
    {
        a[i].n=i;
        a[i].e=1;
    }
    for(int i=2;i<=100000;i++)
    {
        if(a[i].e==1)
        {
            for(int j=1;j<=100000/i;j++)
            {
                a[j*i].e*=i;
            }
        }
    }
    sort(a+1,a+100001,cmp);
    for(int i=1;i<=100;i++)
    {
        cout<<a[i].e<<endl;
    }
    cout<<a[10000].n<<endl;
}
