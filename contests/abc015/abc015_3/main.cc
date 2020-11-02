#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  VV<int> t(n, V<int>(k));
  cin >> t;
  bool ok = Fix([&](auto rec, int depth, int x) {
    if (depth == n) return x != 0;
    rep(i, k) if (!rec(depth + 1, x ^ t[depth][i])) return false;
    return true;
  })(0, 0);
  wt(ok ? "Nothing" : "Found");
}
