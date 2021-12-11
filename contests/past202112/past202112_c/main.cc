#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<bool> ac(6);
  V<int> ans(6);
  rep(i, n) {
    strings(p, v);
    int idx = p[0] - 'A';
    if (v == "AC" && !ac[idx]) {
      ac[idx] = true;
      ans[idx] = i + 1;
    }
  }
  each(e, ans) wt(e);
}
