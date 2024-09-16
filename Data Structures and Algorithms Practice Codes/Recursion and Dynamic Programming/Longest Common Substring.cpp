#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int l1 = s1.length();
  int l2 = s2.length();
  int l3 = s3.length();
  int ans = 0;
  int dp[101][101][101];
  for (int i = 0; i <= l1; i++) {
    for (int j = 0; j <= l2; j++) {
      for (int k = 0; k <= l3; k++) {
        if (i == 0 || j == 0 || k == 0) {
          dp[i][j][k] = 0;
        } else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s2[k - 1]) {
          dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
          ans = max(ans, dp[i][j][k]);
        } else {
          dp[i][j][k] = 0;
        }
      }
    }
  }

  cout << ans;
}