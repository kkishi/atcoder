#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(3 * n);
  cin >> a;
  V<int> cnt(n + 1);
  V<int> ans;
  rep(i, 3 * n) {
    if (++cnt[a[i] - 1] == 2) ans.eb(a[i]);
  }
  wt(ans);
}
