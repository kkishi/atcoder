#include <bits/stdc++.h>

#include "atcoder.h"

struct P {
  int x = 0, y = 0;
};

bool operator<(const P& a, const P& b) { return tie(a.x, a.y) < tie(b.x, b.y); }
bool operator==(const P& a, const P& b) {
  return tie(a.x, a.y) == tie(b.x, b.y);
}

void Main() {
  ints(t);
  rep(t) {
    ints(b, k, sx, sy, gx, gy);
    P s = {sx, sy};
    P g = {gx, gy};
    auto dist = [](P a, P b) { return abs(a.x - b.x) + abs(a.y - b.y); };
    map<P, V<pair<P, int>>> mp;
    auto add = [&](P a, P b, int d) {
      mp[a].eb(b, d);
      mp[b].eb(a, d);
    };
    add(s, g, dist(s, g) * k);
    auto f = [&](P p) {
      V<P> v;
      int x = p.x - p.x % b;
      v.pb({x + 0, p.y});
      v.pb({x + b, p.y});
      int y = p.y - p.y % b;
      v.pb({p.x, y + 0});
      v.pb({p.x, y + b});
      each(e, v) add(p, e, dist(p, e) * k);
      V<P> w;
      rep(i, 2) rep(j, 2) w.pb({x + i * b, y + j * b});
      each(e, v) each(f, w) {
        if (e.x == f.x || e.y == f.y) add(e, f, dist(e, f));
      }
      each(e, w) v.eb(e);
      return v;
    };
    auto sv = f(s);
    auto gv = f(g);
    each(s, sv) each(g, gv) {
      bool sx = s.x % b == 0;
      bool sy = s.y % b == 0;
      bool gx = g.x % b == 0;
      bool gy = g.y % b == 0;
      if (!sx) {
        if (!gx) add(s, g, abs(s.y - g.y) * k + abs(s.x - g.x));
      } else if (!sy) {
        if (!gy) add(s, g, abs(s.x - g.x) * k + abs(s.y - g.y));
      } else {
        assert(sx && sy);
        if (gx && gy) add(s, g, dist(s, g));
      }
    }
    map<P, int> dp;
    dp[s] = 0;
    low_priority_queue<pair<int, P>> que;
    que.emplace(0, s);
    while (!que.empty()) {
      auto [d, p] = que.top();
      if (p == g) {
        wt(d);
        break;
      }
      que.pop();
      if (dp[p] < d) continue;
      each(q, w, mp[p]) {
        int nd = d + w;
        auto [it, ok] = dp.insert({q, nd});
        if (ok || chmin(it->second, nd)) {
          dp[q] = nd;
          que.emplace(nd, q);
        }
      }
    }
  }
}
