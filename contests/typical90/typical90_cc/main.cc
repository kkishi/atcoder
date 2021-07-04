#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  VV<int> v(5000);
  rep(n) {
    ints(a, b);
    --a, --b;
    v[a].pb(b);
  }
  V<int> cnt(5000);
  int ans = 0;
  rep(i, 5000) {
    int j = i - k - 1;
    if (j >= 0) each(e, v[j])-- cnt[e];
    each(e, v[i])++ cnt[e];
    int sum = 0;
    rep(j, 5000) {
      int l = j - k - 1;
      if (l >= 0) sum -= cnt[l];
      sum += cnt[j];
      chmax(ans, sum);
    }
  }
  wt(ans);
}
