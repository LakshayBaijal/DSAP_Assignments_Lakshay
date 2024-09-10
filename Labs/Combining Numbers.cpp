
// While studying late at the IIIT Hyderabad library, you discover an old, dusty book tucked away in a forgotten corner. Inside, there's a mysterious note left by a group of legendary alumni. The note presents a challenge: solve this puzzle, and you will unlock a secret room rumored to hold rare programming resources.

// The puzzle is simple but tricky:

// "Find all valid combinations of numbers that sum to a specific value. Use only the digits from 1 to 9, and each number can only be used once. The number of digits you use is crucial to solving the puzzle, and the correct sum will lead you to the key."

// Your Task: Write a program to find all valid combinations of k numbers that sum up to n with these rules:

// Only numbers from 1 through 9 can be used.
// Each number can only be used once.
// No combination should repeat.
// Rearrangements lead to same combination.
// Input Format

// The input consists of two integers:

// k: The number of digits to be used in the combination.
// n: The target sum that the combination of digits must equal.
// Constraints

// 2 <= k <= 9

// 1 <= n <= 60

// Output Format

// The output is a list of lists, where each inner list contains a valid combination of k numbers that sum up to n.
// Each combination should be sorted in ascending order.
// The list should not contain duplicate combinations.
// Sample Input 0

// 3 24
// Sample Output 0

// 7 8 9 




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

