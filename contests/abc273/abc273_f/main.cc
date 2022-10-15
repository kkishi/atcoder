#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> y(n), z(n);
  cin >> y >> z;
  map<int, int> ym;
  rep(i, n) ym[y[i]] = i;

  V<int> v;
  v.eb(0);
  each(e, y) v.eb(e);
  each(e, z) v.eb(e);
  v.eb(x);
  sort(v);

  int init = lower_bound(all(v), 0) - v.begin();

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
    int pos = v[(d == 0 ? l : r)];
    if (pos == x) {
      wt(w);
      return;
    }
    auto check = [&](int ypos) -> bool {
      auto it = ym.find(ypos);
      if (it == ym.end()) return true;
      int zpos = z[it->second];
      return v[l] <= zpos && zpos <= v[r];
    };
    // Go left
    if (l - 1 >= 0) {
      auto npos = v[l - 1];
      if (check(npos)) {
        push({l - 1, r, 0}, w + pos - npos);
      }
    }
    // Go right
    if (r + 1 < sz(v)) {
      auto npos = v[r + 1];
      if (check(npos)) {
        push({l, r + 1, 1}, w + npos - pos);
      }
    }
  }
  wt(-1);
}
