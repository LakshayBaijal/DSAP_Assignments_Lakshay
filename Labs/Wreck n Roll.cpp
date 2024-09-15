
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