#include <bits/stdc++.h>

using namespace std;

int denomination(int n, int money, vector<int> &coins) {
  if (n == 0) {
    {
      if ((money % coins[0] == 0)) {
        return money / coins[0];
      }
      return INT_MAX;
    }
  }

  int notpick = 0 + denomination(n - 1, money, coins);
  int pick = INT_MAX;
  if (coins[n] <= money) {
    pick = 1 + denomination(n, money - coins[n], coins);
  }
  return min(pick, notpick);
}

int main() {
  int n, money, i;
  vector<int> coins;
  cin >> n;
  cin >> money;

  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    coins.push_back(x);
  }

  int ans = denomination(n - 1, money, coins);
  if (ans == INT_MAX) {
    cout << "No valid solution" << endl;
  } else {
    cout << ans << endl;
  }
}