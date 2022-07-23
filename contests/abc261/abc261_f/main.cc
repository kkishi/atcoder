#include <bits/stdc++.h>
#include <pbds.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(n);
  V<tuple<int, int, int>> v;
  V<int> c(n), x(n);
  cin >> c >> x;
  rep(i, n) v.eb(x[i] - 1, i, c[i] - 1);
  sort(v);
  BIT<int> b(n);
  int ans = 0;
  V<Set<int>> st(n);
  rep(i, n) {
    auto [_, x, c] = v[i];
    b.Add(x, 1);
    ans += i + 1 - b.Sum(x);
    ans -= sz(st[c]) - st[c].order_of_key(x);
    st[c].insert(x);
  }
  wt(ans);
}
