#include"mymath.h"

int s[600];

int main()
{
    freopen("D-large-practice.in","r",stdin);
    freopen("D-large-practice.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,size;
        cin>>n>>size;
        for(int j=0;j<n;j++)
        {
            cin>>s[j];
        }
        sort(s,s+n);
        reverse(s,s+n);
        long long cost = 0;
        long long cnt = 0;
        int last = s[0];
        s[n] = -1;
        for(int j=0;j<=n;j++)
        {
            if(s[j]==last)cnt++;
            else
            {
                long long rem = size/mypow(2,last);
                long long b = rem*rem;
                if( b == 0 ) cout<<last<<" "<<size<<endl;
                assert(b!=0);
                cost = max(cost,(cnt+b-1)/b);
                //cout<<cnt<<' '<<(cnt+0.0)/((size/mypow(2,last))*(size/mypow(2,last)))<<endl;
                cnt*=(long long)mypow(2,last-s[j])*mypow(2,last-s[j]);
                cnt++;
                last = s[j];
            }
        }
        cout<<"Case #"<<i<<": "<<cost<<endl;
    }
}
