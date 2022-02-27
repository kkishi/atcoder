#include <bits/stdc++.h>

#include "atcoder.h"

template <typename S, typename C>
map<S, C> Dijkstra(S s, function<void(S, C, function<void(S, C)>)> f) {
  low_priority_queue<pair<C, S>> que;
  map<S, C> dist;
  auto push = [&](S s, C c) {
    auto [it, ok] = dist.emplace(s, c);
    if (ok || it->second > c) {
      it->second = c;
      que.emplace(c, s);
    }
  };
  push(s, 0);
  while (!que.empty()) {
    auto [c, s] = que.top();
    que.pop();
    if (dist[s] < c) continue;
    f(s, c, push);
  }
  return dist;
}

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
  using S = pair<int, int>;
  auto dist = Dijkstra<S, int>({sx, sy}, [&](S s, int c, auto push) {
    auto [x, y] = s;
    auto f = [](int x, int y, const map<int, V<int>>& xs) -> V<S> {
      V<S> ret;
      auto it = xs.find(y);
      if (it != xs.end()) {
        const auto& v = it->second;
        auto it = lower_bound(all(v), x);
        if (it != v.begin()) ret.eb(*prev(it) + 1, y);
        if (it != v.end()) ret.eb(*it - 1, y);
      }
      return ret;
    };
    each(q, f(x, y, xs)) push(q, c + 1);
    each(q, f(y, x, ys)) push(S{q.second, q.first}, c + 1);
  });
  S g = {gx, gy};
  if (dist.count(g)) {
    wt(dist[g]);
  } else {
    wt(-1);
  }
}
