#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  ints(sx, sy);
  ints(gx, gy);
  map<int, V<int>> xs, ys;
  rep(n) {
    ints(x, y);
    xs[y].pb(x);
    ys[x].pb(y);
  }
  each(_, v, xs) sort(all(v));
  each(_, v, ys) sort(all(v));
  using P = pair<int, int>;
  map<P, int> dist;
  P s = {sx, sy};
  dist[s] = 0;
  queue<P> que;
  que.push(s);
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    auto [x, y] = p;
    auto f = [](int x, int y, const map<int, V<int>>& xs) -> V<P> {
      V<P> ret;
      auto it = xs.find(y);
      if (it != xs.end()) {
        const auto& v = it->second;
        auto it = lower_bound(all(v), x);
        if (it != v.begin()) ret.eb(*prev(it) + 1, y);
        if (it != v.end()) ret.eb(*it - 1, y);
      }
      return ret;
    };
    auto push = [&](P q) {
      if (!dist.count(q)) {
        dist[q] = dist[p] + 1;
        que.push(q);
      }
    };
    each(q, f(x, y, xs)) push(q);
    each(q, f(y, x, ys)) push(P{q.second, q.first});
  }
  P g = {gx, gy};
  if (dist.count(g)) {
    wt(dist[g]);
  } else {
    wt(-1);
  }
}
