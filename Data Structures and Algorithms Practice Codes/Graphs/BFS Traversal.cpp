#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cout << "Total Nodes";
  cin >> n;

  cout << "Total Edges";
  cin >> m;

  vector<int> adjlist[n];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  int vis[n];
  vis[n] = {0};
  vis[0] = 1;
  queue<int> q;

  q.push(0);
  vector<int> bfs;
  while (q.empty() == false) {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto it : adjlist[node]) {
      if (vis[it] == 0) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }

  for (auto it : bfs) {
    cout << it << " ";
  }
}
