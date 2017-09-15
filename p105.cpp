#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<sstream>
#include<cstdio>
using namespace std;

int n;
int a[20];
int aa=0;
bool flag=true;
bool ff=false;

void bfs(int step)
{
    for(int j=-1;j<=1;j++)
    {
        aa+=j*a[step];
        if(aa==0&&step==n)
        {
            if(ff==false)ff=true;
            else flag=false;
        }
        if(step<n)bfs(step+1);
        aa-=j*a[step];
    }
}

int main()
{
    int sum=0;
    freopen("sets.txt","r",stdin);
    string k;
    while(getline(cin,k))
    {
        flag=true;
        ff=false;
        aa=0;
        int cnt=1;
        istringstream ssin;
        ssin.str(k);
        while(ssin>>a[cnt])
        {
            cnt++;
        }

        n=cnt-1;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';
        cout<<endl;
        if(n%2==0)
        {
            int s=0;
            for(int i=1;i<=n/2;i++)s+=a[i];
            for(int i=n/2+2;i<=n;i++)s-=a[i];
            if(s<=0)
            {
                flag=false;
            }
        }
        else
        {
            int s=0;
            for(int i=1;i<=(n+1)/2;i++)s+=a[i];
            for(int i=(n+1)/2+1;i<=n;i++)s-=a[i];
            if(s<=0)
            {
                flag=false;
            }
        }
        bfs(1);
        if(flag==false)cout<<"false"<<endl;
        else
        {
            for(int i=1;i<=n;i++)sum+=a[i];
        }
    }
    cout<<sum<<endl;


}
