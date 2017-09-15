#include<iostream>
using namespace std;


bool isbounce(int a)
{
    int tmp = -1;
    int up = 0;
    while(a!=0)
    {
        int t = a%10;
        if(tmp==-1)tmp = t;
        else
        {
            if(up==0)
            {
                if(t>tmp)up=1;
                if(t<tmp)up=-1;
            }
            else
            {
                if(t>tmp&&up==-1)return true;
                if(t<tmp&&up==1)return true;
            }
        }
        tmp = t;
        a=a/10;
    }
    return false;
}

int main()
{
    int cnt = 0;
    int tot = 0;
    while(1)
    {
        cnt++;
        if(isbounce(cnt))tot++;
        if((tot+0.0)/cnt>=0.99)
        {
            cout<<cnt<<endl;
            break;
        }
    }
}
