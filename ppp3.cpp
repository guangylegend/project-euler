#include"mymath.h"

bool lessthan(string a,string b)
{
    for(int i=0;i<min(a.length(),b.length());i++)
    {
        if(i==a.length()-1)return true;
        else if(i==b.length()-1)return false;
        if(a[i]<b[i])return true;
        else if(a[i]>b[i])return false;
    }
}

int main()
{
    freopen("C-small-practice-2.in","r",stdin);
    freopen("C-small-practice-2.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        string tmp;
        char ppp;
        scanf("%c",&ppp);
        int cnt = 0;
        getline(cin,tmp);
        for(int j=1;j<=m-1;j++)
        {
            string xxx;
            getline(cin,xxx);
            if(lessthan(tmp,xxx))
            {
                tmp = xxx;
            }
            else cnt++;
        }
        cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
}
