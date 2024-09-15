// In a 2D game, a stream of cars enters the screen, each with a different size and moving either right or left. Their direction is indicated by a sign - positive for right, negative for left.

// When the cars moving in opposite directions collide head-on, the smaller car is destroyed. If two cars of the same size crash, they both get wrecked. However, if they’re moving in the same direction, they will not collide.

// Determine which cars are still on the screen after all the collisions. Return the remaining cars in the order they appear.

// Note: Initially, every car is at its index position i

// Input Format

// The first line of the input is an integer n, the total number of cars.

// The second line of input consists of n integers, where each integer represents the size of a car. The sign of the integer (positive or negative) indicates the direction the car is moving in.

// Constraints

// 2 <= n <= 10^6

// -10^5 <= carSize[i] <= 10^5

// carSize[i] != 0

// Output Format

// Return the remaining cars on the screen in the order they appear (seperated by space) after all collisions.

// Simply print 0, if there are no more remaining cars.

// Sample Input 0

// 3
// 4 12 -6
// Sample Output 0

// 4 12
// Sample Input 1

// 4
// 5 10 -10 -5
// Sample Output 1

// 0
// Sample Input 2

// 2
// -10 41
// Sample Output 2

// -10 41


#include <bits/stdc++.h>
#include <queue>
using namespace std;

void accident(stack<int> &s, int x) {
  if (s.size() == 0) {
    s.push(x);
    return;
  }

  if (s.top() < abs(x)) {
    s.pop();
    accident(s, x);
  } else if (s.top() == abs(x)) {
    s.pop();
  } else {
    return;
  }
}

int main() {
  stack<int> s;
  int n, x;
  cin >> n;
  cin >> x;
  s.push(x);
  for (int i = 0; i < n - 1; i++) {
    cin >> x;

    if (s.top() < 0 && x < 0) {
      s.push(x);
    } else if (s.top() < 0 && x > 0) {
      s.push(x);
    }

    else if (s.top() > 0 && x > 0) {
      s.push(x);
    }

    else if (s.top() > 0 && x < 0) {
      accident(s, x);
    }
  }

  for (int i = 0; i <= s.size(); i++) {
    cout << s.top() << " ";
    s.pop();
  }

  return 0;
}
