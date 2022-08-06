#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector c(1 << n, vector(n, int(0)));
  cin >> c;
  map<tuple<int, int, int>, int> mp;
  wt(Fix([&](auto rec, int l, int r, int w) -> int {
    if (r - l == 1) return 0;
    if (w < l || r <= w) w = -1;
    auto [it, ok] = mp.emplace(tuple{l, r, w}, 0);
    if (!ok) return it->second;
    int m = (r + l) / 2;
    int ret = 0;
    if (w == -1) {
      rep(i, l, r) {
        auto log2 = [](int x) { return __builtin_ctzll(x); };
        int res = c[i][log2(r - l) - 1];
        res += rec(l, m, i);
        res += rec(m, r, i);
        chmax(ret, res);
      }
    } else {
      ret += rec(l, m, w);
      ret += rec(m, r, w);
    }
    it->second = ret;
    return ret;
  })(0, 1 << n, -1));
}
