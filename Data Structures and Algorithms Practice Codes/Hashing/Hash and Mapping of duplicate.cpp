#include<bits/stdc++.h>
using namespace std;

int main()
{
  int i,n,hl;
  cin>>n;
  
  int arr[n];

  for(i=0;i<n;i++)
    {
      cin>>arr[i];
    }

  cout<<"Enter Hash Table Length";
  cin>>hl;
  
  
  map <int,int> mpp;

  for(i=0;i<n;i++)
    {
      mpp[arr[i]]++;
    }
  
  for(auto it : mpp)
    {
      cout<<it.first<<" "<<it.second<<endl;
    }



  return 0;


  
}