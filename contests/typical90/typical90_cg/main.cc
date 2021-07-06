#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(k);
  auto fs = Factors(k);
  using A = array<int, 3>;
  set<A> st;
  Fix([&](auto rec, auto it, A v) {
    if (it == fs.end()) {
      sort(all(v));
      st.insert(v);
      return;
    }
    auto [x, y] = *it;
    rep(i, y + 1) rep(j, i, y + 1) {
      rec(next(it), A{v[0] * int_pow(x, i), v[1] * int_pow(x, j - i),
                      v[2] * int_pow(x, y - j)});
    }
  })(fs.begin(), A{1, 1, 1});
  wt(sz(st));
}
