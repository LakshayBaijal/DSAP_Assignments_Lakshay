#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cout << "Total Nodes";
  cin >> n;

  cout << "Total Edges";
  cin >> m;

  vector<int> adjlist[n + 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  for (int i = 0; i < n; i++) {
    cout << i << " Edge->";
    for (auto vertex : adjlist[i]) {
      cout << " " << vertex << " ";
    }
    cout<<endl;
  }
}
