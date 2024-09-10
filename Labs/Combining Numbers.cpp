#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, int k, vector<int>& temp, vector<vector<int>>& ans) {
    if (n == 0 && k == 0) {
        ans.push_back(temp);
        return;
    }

    if (n < 0 || k < 0 || i > 9) {
        return;
    }

    // Include the current number i
    temp.push_back(i);
    solve(i + 1, n - i, k - 1, temp, ans);  // Decrement `n` by `i`
    temp.pop_back();  // Backtrack

    // Exclude the current number and move to the next
    solve(i + 1, n, k, temp, ans);
}

vector<vector<int>> combinationSum(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(1, n, k, temp, ans);
    return ans;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<vector<int>> answer = combinationSum(k, n);

    for (const vector<int>& vec : answer) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}