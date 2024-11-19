#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[i] = 1;
    for(auto it : adj[i])
      {
        if(!vis[it])
        {
          vis[it] = 1;
          dfs(it, vis, adj);
        }
      }
}

int main() 
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++)
    {
      int x,y;
      cin>>x>>y;
      x--;
      y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

  vector<int> vis(n,0);
  int count = 0;
  for(int i=0;i<n;i++)
    {
      if(vis[i]==0)
      {
        dfs(i,vis,adj);
        count++;
      }      
    }  
  cout<<count<<endl;
}