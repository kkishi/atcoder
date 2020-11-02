#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;
  int sum = accumulate(all(a), 0LL);
  map<int, int> fs = Factorize(sum);
  vector<pair<int, int>> v(all(fs));

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

  wt(Fix([&](auto dfs, int depth, int g) -> int {
    if (depth == v.size()) {
      return check(g) ? g : 0;
    }
    int ret = 0;
    rep(i, v[depth].second + 1) {
      chmax(ret, dfs(depth + 1, g));
      g *= v[depth].first;
    }
    return ret;
  })(0, 1));
}
