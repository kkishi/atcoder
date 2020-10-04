#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

void Main() {
  ints(n);
  V<int> x(n);
  cin >> x;

  V<int> ord(n - 1);
  rep(i, n - 1) ord[i] = i;
  int ans = 0;
  V<int> cnt(n - 1);
  do {
    V<bool> moved(n);
    rep(i, n - 1) {
      int j = ord[i];
      moved[j] = true;
      do {
        ans += x[j + 1] - x[j];
        ++cnt[j];
        ++j;
      } while (moved[j]);
    }
  } while (next_permutation(all(ord)));
  wt(ans);
  dbg(cnt);
}
