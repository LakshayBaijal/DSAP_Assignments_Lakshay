#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    vector <int> v;
    int i,j,k;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cin>>k;
    
    int max_len=0;
    for(i=0;i<n;i++)
    {
        int x = k;
        int count=0;

        for(j=i;j<n;j++)
        {
            if(x > 0 || v[j]!=0)
            {
                if(v[j]==0)
            {
               x--;
               count++;
            }
            else
            {
                count++;
            }
            }
            else
            {
                break;
            }
        }
        if(max_len<count)
        {
            max_len = count;
        }
    }
    
    cout<<max_len;
    return 0;
}
