#include"mymath.h"

int main()
{
    string s;
    int numRows;
    cin>>s>>numRows;
    vector<vector<char>> v;
    for(int i=1;i<=numRows;i++)
    {
        vector<char> vv;
        v.push_back(vv);
    }
        bool down = true;
        int cnt = 1;
        for(int i=0;i<s.length();i++)
        {
            if(down)
            {
                v[cnt-1].push_back(s[i]);
                if(cnt==numRows)
                {
                    cnt--;
                    down = false;
                }
                else cnt++;
            }
            else
            {
                v[cnt-1].push_back(s[i]);
                if(cnt==1)
                {
                    cnt++;
                    down = true;
                }
                else cnt--;
            }
        }
        string out = "";
        for(int i=0;i<v.size();i++)
            for(int j=0;j<v[i].size();j++)
                out+=v[i][j];
        cout<<out<<endl;
}
