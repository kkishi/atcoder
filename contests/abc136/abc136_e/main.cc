#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;

  auto check = [&](int g) {
    vector<int> mods(n);
    rep(i, n) mods[i] = a[i] % g;
    sort(all(mods));
    vector<int> upper(n + 1);
    rrep(i, n) upper[i] = upper[i + 1] + g - mods[i];
    vector<int> lower(n + 1);
    rep(i, n) lower[i + 1] = lower[i] + mods[i];
    rep(i, n) {
      int l = lower[i + 1], u = upper[i + 1];
      if (l > k) continue;
      if (l == u) return true;
    }
    return false;
  };

  int ans = 0;
  each(g, Divisors(accumulate(a))) {
    if (check(g)) chmax(ans, g);
  }
  wt(ans);
}
