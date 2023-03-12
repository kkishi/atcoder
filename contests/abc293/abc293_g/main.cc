#include <bits/stdc++.h>

#include "atcoder.h"
#include "mo.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  V<pair<int, int>> qs;
  rep(q) {
    ints(l, r);
    qs.eb(l - 1, r);
  }

  V<i32> v(200001);
  int ans = 0;
  auto calc = [](int x) -> int {
    if (x < 3) return 0;
    return x * (x - 1) * (x - 2) / 6;
  };
  auto add = [&](int i) {
    auto& x = v[a[i]];
    ans -= calc(x);
    ++x;
    ans += calc(x);
  };
  auto del = [&](int i) {
    auto& x = v[a[i]];
    ans -= calc(x);
    --x;
    ans += calc(x);
  };
  auto get = [&] { return ans; };

  each(e, Mo(add, del, get, qs)) wt(e);
}
