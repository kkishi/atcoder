#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<bool> f(n + 1);
  rep(m) {
    ints(a);
    f[a] = true;
  }
  V<int> ans(n);
  int last = 0;
  rrep(i, 1, n + 1) {
    if (f[i]) last = i;
    ans[i - 1] = last - i;
  }
  each(e, ans) wt(e);
}
