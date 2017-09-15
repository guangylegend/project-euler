#include"mymath.h"

long double s[1005];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cout.setf(ios::fixed);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++)cin>>s[j];
        for(int j=1;j<=m;j++)
        {
            int l,r;
            cin>>l>>r;
            long double sum = 1;
            for(int k=l;k<=r;k++)
            {
                sum*=s[k];
            }
            cout<<setprecision(9)<<pow(sum,1.0/(r-l+1))<<endl;
        }
    }
}
