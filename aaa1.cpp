#include"mymath.h"

int recur(long long int n, long long int k, bool chan)
{
    //cout<<n<<' '<<k<<' '<<chan<<endl;
    if(2*k-1 == n)return chan;
    else if(2*k-1<n)
    {
        return recur((n-1)/2,k,chan);
    }
    else
    {
        return recur((n-1)/2,n+1-k,!chan);
    }
}


int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    cin>>t;
    long long int k = 0;
    for(int i=1;i<=62;i++)
    {
        k = 2*k+1;
    }
    //cout<<k<<endl;
    for(int i=1;i<=t;i++)
    {
        long long int n;
        cin>>n;
        cout<<"Case #"<<i<<": "<<recur(k,n,false)<<endl;
    }

}
