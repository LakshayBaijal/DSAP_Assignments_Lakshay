// Max and his grandfather Dr. Quantum find themselves on Planet X after a
// series of wacky adventures. They realize that they're trapped on this
// peculiar planet and can't leave. Currently, Max and Quantum are on Lily Pad
// 0. In order to escape, they need to get to Lily Pad N, which is their only
// way off the planet. However, there's a tricky monster guarding Lily Pad N.
// This monster will only let them pass if they can correctly tell the number of
// possible paths to jump to Lily Pad N.

// The twist is that the celestial paths connect the Lily Pads in a unique
// pattern. If they're on Lily Pad i, the celestial paths will take them to Lily
// Pad (i+2), (i+3), and (i+5). Max's usually unsure of himself, but this time,
// Quantum believes in him and asks him to calculate the number of paths they
// can take to reach Lily Pad N.

// Since the answer can be very large, print the modulo (10^9 + 7) of the number
// of possible ways.

// Input Format

// First Line of input will contain T, the number of testcases For each
// subsequent T lines, there is a single interger N, denoting the lily pad Max
// and Quantum to escape from.

// Constraints

// For 80% points:

// 1 <= T <= 10

// 1 <= N <= 40

// For 100% points:

// 1 <= T <= 1000

// 1 <= N <= 1000

// Output Format

// Print a single integer, denoting the number of possible ways to reach lily
// pad N.

#include <bits/stdc++.h>
using namespace std;

void Celestial(int n, int &total) {
  if (n == 0) {
    total++;
    return;
  }
  if (n < 0) {
    return;
  }
  Celestial(n - 2, total);
  Celestial(n - 3, total);
  Celestial(n - 5, total);
  return;
}

int main() {

  int n;

  cin >> n;
  int total = 0;
  Celestial(n, total);
  cout << total;
}