#include <bits/stdc++.h>

#include "atcoder.h"
#include "mo.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  V<pair<int, int>> qs;
  ints(q);
  rep(q) {
    ints(l, r);
    qs.eb(l - 1, r);
  }

  V<int> cnt(n);
  int x = 0;
  auto add = [&](int i) {
    if (even(++cnt[a[i] - 1])) ++x;
  };
  auto del = [&](int i) {
    if (even(cnt[a[i] - 1]--)) --x;
  };
  auto get = [&]() { return x; };

  each(e, Mo(add, del, get, qs)) wt(e);
}
