#include"mymath.h"
#include<set>

int num[10] = {1111110,110000,1101101,1111001,110011,1011011,1011111,1110000,1111111,1111011};
int tmp[105];
int broken[10];
int fl[10];

set<int> s;

int mul(int n,int k)
{
    int ans = 1;
    while(k--)ans*=n;
    return ans;
}

bool contain(int a,int aux,int b)
{
    for(int i=0;i<=6;i++)
    {
        int p = mul(10,i);
        if((a/p)%10>(b/p)%10 || (a/p)%10+(aux/p)%10<(b/p)%10 )return false;
    }
    for(int i=0;i<=6;i++)
    {
        int p = mul(10,i);
        if((b/p)%10==1)fl[i]=1;
    }
    return true;
}

int xo(int a,int b)
{
    int ans = a;
    for(int i=0;i<=6;i++)
    {
        int p = mul(10,i);
        if((a/p)%10==1 && (b/p)%10==1)
        {
            ans-=p;
        }
    }
    return ans;
}


int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int add = 0;
        int m;
        cin>>m;
        memset(tmp,0,sizeof(tmp));
        memset(broken,0,sizeof(broken));
        s.clear();
        for(int j=1;j<=m;j++)
        {
            cin>>tmp[j];
            for(int k=0;k<7;k++)
            {
                int p = mul(10,k);
                if(broken[k]==0 && ((tmp[j]/p)%10)==1)
                {
                    broken[k]=1;
                }
            }
        }
        for(int k=0;k<7;k++)
        {
            if(broken[k]==0)add+=mul(10,k);
        }
        for(int i=0;i<10;i++)
        {
            bool flag = false;
            memset(fl,0,sizeof(fl));
            for(int j=1;j<=m;j++)
            {
                int t = i-j+1;
                while(t<0)t+=10;
                if(!contain(tmp[j],add,num[t]))
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {

                int t = i-m;
                while(t<0)t+=10;
                for(int i=0;i<=6;i++)
                {
                    int p = mul(10,i);
                    if((num[t]/p)%10==1 && fl[i]==0)s.insert(2);
                }
                s.insert(xo(num[t],add));
            }
        }

        if(s.size()==0 || s.size()>1)cout<<"Case #"<<i<<": ERROR!"<<endl;
        else
        {
            set<int>::iterator iter = s.begin();
            printf("Case #%d: %07d\n",i,*iter);
        }
    }
}
