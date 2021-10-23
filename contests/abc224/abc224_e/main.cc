#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  V<tuple<int, int, int, int>> v;
  rep(i, n) {
    ints(r, c, a);
    v.eb(a, i, r - 1, c - 1);
  }
  sort(all(v), greater{});
  V<int> R(h, -1), C(w, -1);
  int i = 0;
  V<int> ans(n);
  while (i < n) {
    int j = i;
    while (j < n && get<0>(v[j]) == get<0>(v[i])) {
      ++j;
    }
    V<tuple<int, int, int>> u;
    rep(k, i, j) {
      auto [_, idx, r, c] = v[k];
      int x = max(R[r], C[c]) + 1;
      ans[idx] = x;
      u.eb(r, c, x);
    }
    for (auto [r, c, x] : u) {
      chmax(R[r], x);
      chmax(C[c], x);
    }
    i = j;
  }
  rep(i, n) wt(ans[i]);
}
