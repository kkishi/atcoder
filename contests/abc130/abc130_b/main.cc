#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  vector<int> l(n);
  cin >> l;
  int ans = 1;
  int cx = 0;
  rep(i, n) {
    cx += l[i];
    if (cx <= x) ++ans;
  }
  wt(ans);
}
