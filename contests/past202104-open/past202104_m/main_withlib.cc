#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n);
  Intervals is;
  unordered_map<int, int> cnt;
  int ans = 0;
  auto change = [&](int x, int v) {
    auto f = [](int x) { return x * (x - 1) / 2; };
    ans -= f(cnt[x]);
    cnt[x] += v;
    ans += f(cnt[x]);
  };
  rep(i, n) {
    ints(a);
    is.Insert(i, i + 1, a);
    change(a, 1);
  }
  ints(q);
  rep(q) {
    ints(l, r, x);
    --l;
    for (auto [l, r, x] : is.Erase(l, r)) {
      change(x, -(r - l));
    }
    is.Insert(l, r, x);
    change(x, r - l);
    wt(ans);
  }
}
