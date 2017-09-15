#include"mymath.h"
#include<assert.h>

const double g = 9.8;
const double pi = 3.1415926535897;
int main()
{
    freopen("B-small-practice.in","r",stdin);
    freopen("B-small-practice.out","w",stdout);
    cout.setf(ios::fixed);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int vv,DD;
        cin>>vv>>DD;
        long double v = vv,D = DD;
        long double t2;
        if(abs(v*v*v*v-g*g*D*D)<1e-4)t2 = 2*v*v/(g*g);
        else t2 = 2*(v*v-sqrt(v*v*v*v-g*g*D*D))/(g*g);
        long double theta = atan(g*t2/(2*D))/pi*180;
        assert(!isnan(theta));
        cout<<"Case #"<<i<<": "<<setprecision(7)<<theta<<endl;
    }
}
