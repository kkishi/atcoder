#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  set<int> s;
  Fix([&](auto rec, int depth, int x) {
    if (depth == n) {
      s.insert(x);
      return;
    }
    int ten = int_pow(10, depth);
    rep(i, a[depth] + 1) {
      rec(depth + 1, x);
      x += ten;
    }
  })(0, 0);
  wt(sz(s) - 1);
}
