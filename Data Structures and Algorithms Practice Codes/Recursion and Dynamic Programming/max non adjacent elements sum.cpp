#include<bits/stdc++.h>

using namespace std;


int maxnonadj(vector <int> v ,int index)
{
    if(index == 0)
    {
        return v[index];
    }
    if(index < 0)
    {
        return 0;
    }

    int pick = v[index] + maxnonadj(v,index-2);
    int nonpick = maxnonadj(v,index-1);
    

    
    return max(pick,nonpick);
}






int main()
{
    int i;
    int n;
    int max;
    vector <int> v;
    cin>>n;
    for(i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }

    max = maxnonadj(v,n);

    cout << max;
}