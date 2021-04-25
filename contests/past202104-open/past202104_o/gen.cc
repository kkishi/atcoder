#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 100;
  int m = n + 10;
  wt(n, m);
  Rand r;
  set<pair<int, int>> s;
  rep(i, n - 1) {
    int a = i + 1;
    int b = r.Int(0, i);
    s.insert({a, b});
  }
  rep(i, m - (n - 1)) {
    while (true) {
      int a = r.Int(0, n - 1);
      int b = r.Int(0, n - 1);
      if (a == b) continue;
      if (s.count({a, b}) || s.count({b, a})) continue;
      s.insert({a, b});
      break;
    }
  }
  V<int> idx(n);
  iota(all(idx), int(1));
  rep(i, n) swap(idx[i], idx[r.Int(i, n - 1)]);
  each(a, b, s) wt(idx[a], idx[b]);
  int q = n * (n - 1) / 2;
  wt(q);
  rep(i, n - 1) rep(j, i + 1, n) wt(i + 1, j + 1);
}
