#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> rl;
  V<int> rc(n + 1);
  rep(m) {
    ints(l, r);
    rl.eb(r, -l);
    ++rc[r];
  }
  rep(i, n) rc[i + 1] += rc[i];
  sort(all(rl));
  int ans = 0;
  BIT<int> bit(n + 1);
  each(r, l, rl) {
    l = -l;
    ans += rc[l];
    ans += bit.Sum(r) - bit.Sum(l - 1);
    bit.Add(l, 1);
  }
  wt(m * (m - 1) / 2 - ans);
}
