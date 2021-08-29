#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  char c;
  int x, y;
  cin >> x >> c >> y;
  if (y <= 2) {
    cout << x << '-' << endl;
  } else if (y <= 6) {
    cout << x << endl;
  } else {
    cout << x << '+' << endl;
  }
}
