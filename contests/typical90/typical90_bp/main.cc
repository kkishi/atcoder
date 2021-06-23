#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  V<tuple<int, int, int, int>> qs;
  rep(q) {
    ints(t, x, y, v);
    --x, --y;
    qs.eb(t, x, y, v);
  }
  DisjointSet ds(n);
  V<int> diff(n, -1);
  V<int> ans(q);
  rep(i, sz(qs)) {
    auto [t, x, y, v] = qs[i];
    if (t == 0) {
      ds.Union(x, y);
      diff[x] = v;
    } else {
      if (!ds.Same(x, y)) {
        ans[i] = -1;
      }
    }
  }
  V<int> sdiff(n);
  V<int> offset(n);
  rep(i, n) {
    if (diff[i] != -1) {
      offset[i + 1] = offset[i] + 1;
      sdiff[i + 1] = diff[i] - sdiff[i];
    }
  }
  rep(i, sz(qs)) {
    auto [t, x, y, v] = qs[i];
    if (t == 1) {
      if (ans[i] == -1 || !ds.Same(x, y)) {
        wt("Ambiguous");
      } else {
        int z;
        if (even(offset[x])) {
          z = v - sdiff[x];
        } else {
          z = sdiff[x] - v;
        }
        int w;
        if (even(offset[y])) {
          w = sdiff[y] + z;
        } else {
          w = sdiff[y] - z;
        }
        wt(w);
      }
    }
  }
}
