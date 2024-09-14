#include <bits/stdc++.h>
using namespace std;

void comb(vector<int> &v, int index, int total) {
  if (index < 0) {
    cout << total << " ";
    return;
  }
  int i = index;
  comb(v, index - 1, total);
  comb(v, index - 1, total + v[i]);
}

int main() {
  vector<int> v;
  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  int total = 0;

  comb(v, n - 1, total);
  return 0;
}
