#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> ans(n);
  rep(m) {
    ints(a, b);
    ++ans[a - 1];
    ++ans[b - 1];
  }
  rep(i, n) wt(ans[i]);
}
