#include<bits/stdc++.h>

using namespace std;

void binary(int cur,string str,int n)
{
    if(n==0)
    {
        cout<<str <<" ";
        return ;
    }
    
    binary(0,str+'0',n-1);

    if(cur!=1)
    {
        binary(1,str+'1',n-1);
    }

}



int main()
{
    int n;
    string str;
    cin>>n;
    binary(0,"",n);
    
}