#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  V<int> above(n, -1), below(n, -1), top(n);
  iota(all(top), int(0));
  rep(q) {
    ints(f, t, x);
    --f, --t, --x;
    int bx = below[x];
    if (bx != -1) {
      above[bx] = -1;
    }
    if (top[t] != -1) {
      above[top[t]] = x;
    }
    below[x] = top[t];
    top[t] = top[f];
    top[f] = bx;
  }
  V<int> ans(n);
  rep(i, n) {
    for (int j = top[i]; j != -1; j = below[j]) {
      ans[j] = i;
    }
  }
  each(x, ans) wt(x + 1);
}
