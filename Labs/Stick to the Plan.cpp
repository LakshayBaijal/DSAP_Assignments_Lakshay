// During the production of n flagsticks for decorating the institute's football ground for the Independence Day, there was a mix-up, and now the flagsticks are of varying lengths. To ensure a uniform look, the organizers need to adjust all the flagsticks to be the same length.

// You are assigned a task to assist the organizers by finding the optimal length for the flagsticks that will minimize the total cost of adjustment. You can either lengthen or shorten each flagstick, both operations cost x, where x is the difference between the new and original length.

// Task:

// Given n flagsticks with varying lengths and a cost x per unit length adjusted, determine the optimal length for the flagsticks that will minimize the total adjustment cost.
// Input Format

// The first input line contains an integer n: the number of sticks.

// The next input line contains n integers seperated by space(l_1, l_2, ..., l_n): denoting the lengths of the sticks.

// Constraints

// 1 <= n <= 2 * 10^5

// 1 <= l_i <= 10^9

// Output Format

// Print one integer, the minimum total cost.

// Sample Input 0

// 5
// 2 3 1 5 2
// Sample Output 0

// 5




#include <bits/stdc++.h>
using namespace std;

int minimumcost(vector<int> v, int n, int max_length) {
  if (max_length == 0) {
    return INT_MAX;
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    total = total + abs(v[i] - max_length);
  }
  return min(total, minimumcost(v, n, max_length - 1));
}

int main() {
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int max_length = *max_element(v.begin(), v.end());
  cout << minimumcost(v, n, max_length);
}