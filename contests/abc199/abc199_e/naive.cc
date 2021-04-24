#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> v;
  rep(m) {
    ints(x, y, z);
    v.eb(x, y, z);
  }
  int ans = 0;
  V<int> p(n);
  iota(all(p), 1);
  do {
    bool ok = true;
    for (auto [x, y, z] : v) {
      int cnt = 0;
      rep(i, x) if (p[i] <= y)++ cnt;
      if (cnt > z) ok = false;
    }
    if (ok) ++ans;
  } while (next_permutation(all(p)));
  wt(ans);
}
