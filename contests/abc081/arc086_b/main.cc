#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  int maxi = -1;
  rep(i, n) if (maxi == -1 || abs(a[maxi]) < abs(a[i])) maxi = i;
  dbg(maxi);

  V<pair<int, int>> ans;
  rep(i, n) if (i != maxi) {
    a[i] += a[maxi];
    ans.pb({maxi, i});
  }
  if (a[maxi] <= 0) {
    rrep(i, n - 1) {
      a[i] += a[i + 1];
      ans.pb({i + 1, i});
    }
  } else {
    rep(i, n - 1) {
      a[i + 1] += a[i];
      ans.pb({i, i + 1});
    }
  }
  wt(ans.size());
  for (auto [x, y] : ans) wt(x + 1, y + 1);
}
