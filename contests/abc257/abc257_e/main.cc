#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(9);
  cin >> c;
  int mi = min(c);
  int keta = n / mi;
  rep(i, keta) {
    int excess = n - (keta - i) * mi;
    int use;
    rep(j, 9) if (c[j] - mi <= excess) use = j;
    cout << (use + 1);
    n -= c[use];
  }
  cout << endl;
}
