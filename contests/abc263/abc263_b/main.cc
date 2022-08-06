#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  rep(i, n) cin >> p[i + 1];
  int x = n;
  int ans = 0;
  while (x != 1) {
    x = p[x - 1];
    ++ans;
  }
  wt(ans);
}
