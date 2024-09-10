#include <bits/stdc++.h>

using namespace std;

void combinations(vector<int> arr, int n, int target, vector<int> comb,int index) {
  if (index < arr.size()-1) {
    if (target == 0) {
      for (auto it : comb) {
        cout << it << " ";
      }
      cout << endl;
    }
    if (target < 0 && target < arr[index]) {
      return;
    }
    if (arr[index] < target) {

      comb.push_back(arr[index]);

      combinations(arr, n, target - arr[index], comb, index);
      comb.pop_back();
    }
    combinations(arr, n, target, comb, index + 1);
  }

  return;
}

int main() {
  vector<int> arr;
  int n;
  int x;
  int target;
  vector<int> comb;
  cout << "Target";
  cin >> target;
  cout << "Enter the size of the array";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  int index = 0;

  combinations(arr, n, target, comb, index);

  return 0;
}
