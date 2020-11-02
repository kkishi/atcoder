#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  rep(i, n - 1) {
    int x = a[i + 1] - a[i];
    if (x == 0) {
      wt("stay");
    } else if (x < 0) {
      cout << "down " << -x << endl;
    } else {
      cout << "up " << x << endl;
    }
  }
}
