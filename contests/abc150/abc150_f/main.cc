#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash_match.h"

void Main() {
  ints(n);
  vector<bitset<30>> a(n), b(n);
  rep(i, n) {
    ints(x);
    a[i] = x;
  }
  rep(i, n) {
    ints(x);
    b[i] = x;
  }

  vector matches(30, vector(2, vector(n, false)));
  rep(bit, 30) {
    string as, nas, bs;
    rep(i, n) {
      as += '0' + a[i][bit];
      nas += '1' - a[i][bit];
      bs += '0' + b[i][bit];
    }
    bs += bs;
    for (int m : RollingHashMatches(bs, as)) {
      matches[bit][0][m] = true;
    }
    for (int m : RollingHashMatches(bs, nas)) {
      matches[bit][1][m] = true;
    }
  }
  vector<pair<int, int>> ans;
  rep(i, n) {
    bool ok = true;
    rep(j, 30) if (!(matches[j][0][i] || matches[j][1][i])) ok = false;
    if (!ok) continue;
    int x = 0;
    rep(j, 30) x |= (matches[j][1][i]) << j;
    ans.pb({(n - i) % n, x});
  }
  sort(all(ans));
  for (auto [a, b] : ans) wt(a, b);
}
