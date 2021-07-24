#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> c(n);
  cin >> c;
  map<int, int> m;
  int ans = -big;
  rep(i, n) {
    ++m[c[i]];
    int j = i - k;
    if (j >= 0) {
      --m[c[j]];
      if (m[c[j]] == 0) {
        m.erase(c[j]);
      }
    }
    if (i >= k - 1) {
      chmax(ans, sz(m));
    }
  }
  wt(ans);
}
