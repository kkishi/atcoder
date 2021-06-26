#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> w(n), b(n);
  cin >> w >> b;
  map<pair<int, int>, int> dp;
  auto rec = Fix([&](auto rec, int i, int j) -> int {
    auto [it, ok] = dp.insert({pair<int, int>{i, j}, 0});
    if (ok) {
      set<int> seen;
      if (i >= 1) seen.insert(rec(i - 1, j + i));
      for (int k = 1; k <= j / 2; ++k) seen.insert(rec(i, j - k));
      for (int k = 0;; ++k)
        if (!seen.count(k)) {
          it->second = k;
          break;
        }
    }
    return it->second;
  });
  int x = 0;
  rep(i, n) x ^= rec(w[i], b[i]);
  wt(x ? "First" : "Second");
}
