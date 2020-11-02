#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  wt(50);
  V<int> a(50);
  rep(i, 50) a[i] = i;
  int x = k / 50;
  int y = k % 50;
  rep(i, 50) a[i] += x;
  rep(y) {
    int mi, m = numeric_limits<int>::max();
    rep(i, 50) if (chmin(m, a[i])) mi = i;
    rep(i, 50) if (i != mi) {
      assert(a[i] > 0);
      --a[i];
    }
    a[mi] += 50;
  }
  rep(i, 50) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}
