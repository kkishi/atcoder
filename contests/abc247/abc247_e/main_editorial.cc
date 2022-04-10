#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n);
  cin >> a;
  int i = 0;
  auto bet = [&](int z) { return y <= z && z <= x; };
  int ans = 0;
  while (i < n) {
    while (i < n && !bet(a[i])) ++i;
    int j = i;
    while (j < n && bet(a[j])) ++j;

    int l = i, r = i;
    int xs = 0, ys = 0;
    auto ch = [&](int a, int d) {
      if (a == x) xs += d;
      if (a == y) ys += d;
    };
    auto ok = [&]() { return xs > 0 && ys > 0; };
    while (l < j) {
      while (r < j && !ok()) {
        ch(a[r], 1);
        ++r;
      }
      if (!ok()) break;
      ans += j - r + 1;
      ch(a[l], -1);
      ++l;
    }
    i = j;
  }
  wt(ans);
}
