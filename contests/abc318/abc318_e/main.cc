#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, V<int>> mp;
  rep(i, n) mp[a[i]].eb(i);
  int ans = 0;
  each(_, e, mp) {
    int N = sz(e);
    rep(i, N - 1) {
      int d = e[i + 1] - e[i] - 1;
      ans += (i + 1) * (N - i - 1) * d;
    }
  }
  wt(ans);
}
