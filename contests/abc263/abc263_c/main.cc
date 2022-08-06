#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> v(n);
  Fix([&](auto rec, int depth) {
    if (depth == n) {
      wt(v);
      return;
    }
    rep(i, (depth == 0 ? 0 : v[depth - 1]), m) {
      v[depth] = i + 1;
      rec(depth + 1);
    }
  })(0);
}
