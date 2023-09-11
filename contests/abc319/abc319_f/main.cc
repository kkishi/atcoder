// NOTE: This is not correct.
#include <bits/stdc++.h>

#include "atcoder_yn.h"
#include "graph.h"

bool Main() {
  ints(n);
  Graph gr(n);
  V<int> t(n), s(n), g(n);
  rep(i, 1, n) {
    ints(p);
    --p;
    gr[p].eb(i);
    cin >> t[i] >> s[i] >> g[i];
  }
  using T = tuple<int, int>;

  low_priority_queue<T> que;
  int cg = 1;
  V<int> med;
  auto add_edges = [&](int i) {
    each(j, gr[i]) {
      if (t[j] == 1) {
        que.emplace(s[j], j);
      } else {
        med.pb(j);
      }
    }
  };
  add_edges(0);
  while (!que.empty()) {
    auto [_, i] = que.top();
    que.pop();
    if (cg < s[i]) {
      int mip = big;
      int mis;
      rep(i, 1 << sz(med)) {
        int p = 1;
        rep(j, sz(med)) if (hasbit(i, j)) p *= g[med[j]];
        if (cg * p >= _ && chmin(mip, p)) mis = i;
      }
      if (mip == big) return false;
      cg *= mip;
      V<int> nmed;
      rep(j, sz(med)) {
        if (hasbit(mis, j)) {
          add_edges(j);
        } else {
          nmed.eb(med[j]);
        }
      }
      swap(med, nmed);
    }
    if (t[i] == 1) {
      cg += g[i];
      add_edges(i);
    }
  }
  return true;
}
