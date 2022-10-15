#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> y(n), z(n);
  cin >> y >> z;
  using P = tuple<int, int, int>;
  V<P> v;
  v.eb(0, -1, -1);
  rep(i, n) v.eb(y[i], 0, i);
  rep(i, n) v.eb(z[i], 1, i);
  v.eb(x, 2, 2);
  sort(v);
  int N = sz(v);
  int init;
  rep(i, sz(v)) if (get<0>(v[i]) == 0) init = i;
  using S = tuple<int, int, int>;
  low_priority_queue<pair<int, S>> que;
  map<S, int> dist;
  auto push = [&](S s, int w) {
    auto [it, ok] = dist.insert({s, w});
    if (ok || chmin(it->second, w)) que.push({w, s});
  };
  S s = {init, init, 0};
  push(s, 0);
  while (!que.empty()) {
    auto [w, s] = que.top();
    que.pop();
    if (dist[s] < w) continue;
    auto [l, r, d] = s;
    int pos = get<0>(v[(d == 0 ? l : r)]);
    if (pos == x) {
      wt(w);
      return;
    }
    auto check = [&](int idx) -> bool {
      int lp = get<0>(v[l]);
      int rp = get<0>(v[r]);
      return lp <= z[idx] && z[idx] <= rp;
    };
    // Go left
    if (l - 1 >= 0) {
      auto [npos, kind, idx] = v[l - 1];
      if (kind != 0 || check(idx)) {
        int nw = w + abs(pos - npos);
        S ns = {l - 1, r, 0};
        push(ns, nw);
      }
    }
    // Go right
    if (r + 1 < sz(v)) {
      auto [npos, kind, idx] = v[r + 1];
      if (kind != 0 || check(idx)) {
        int nw = w + abs(pos - npos);
        S ns = {l, r + 1, 1};
        push(ns, nw);
      }
    }
  }
  wt(-1);
}
