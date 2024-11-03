#include <bits/stdc++.h>
using namespace std;

void bfstraversal(int node, vector <int> vis, vector<vector<int>> &adjlist) {
  queue<int> q;
  q.push(node);
  vis[node] = 1;

  while (!q.empty()) {
    int temp = q.front();
    q.pop();

    for (auto it : adjlist[temp]) {
      if (vis[it] == 0) { // Only visit unvisited nodes
        vis[it] = 1;
        q.push(it);
      }
    }
  }
}

int main() {
  int n, m;
  cout << "Total Nodes: ";
  cin >> n;

  cout << "Total Edges: ";
  cin >> m;

  vector<vector<int>> adjlist(
      n); // Correct way to initialize the adjacency list

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  vector <int> vis(n,0);
  int count = 0;

  for (int i = 0; i < m; i++) {
    if (vis[i] == 0) {
      count++;
      bfstraversal(i, vis, adjlist);
    }
  }

  cout << "Number of connected components: " << count << endl;
  return 0;
}
