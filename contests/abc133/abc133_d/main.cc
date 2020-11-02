#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  int x0 = 0;
  rep(i, n) x0 += a[i] * ((i & 1) ? -1 : 1);
  x0 /= 2;
  cout << x0 * 2;
  rep(i, n - 1) {
    x0 = (a[i] - x0);
    cout << " " << x0 * 2;
  }
  cout << endl;
}
