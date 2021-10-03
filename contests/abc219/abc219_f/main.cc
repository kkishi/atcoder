#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  using P = pair<int, int>;
  P p = {0, 0};
  vector<P> v;
  v.eb(p);
  each(e, s) {
    if (e == 'L') --p.first;
    if (e == 'R') ++p.first;
    if (e == 'U') --p.second;
    if (e == 'D') ++p.second;
    v.eb(p);
  }
  sort(all(v));
  v.erase(unique(all(v)), v.end());

  if (p == P{0, 0}) {
    wt(sz(v));
    return;
  }

  if (p.first < 0) {
    p.first = -p.first;
    each(e, v) e.first = -e.first;
  }
  if (p.second < 0) {
    p.second = -p.second;
    each(e, v) e.second = -e.second;
  }
  if (p.first > p.second) {
    swap(p.first, p.second);
    each(e, v) swap(e.first, e.second);
  }

  int minx = big, miny = big;
  each(e, v) {
    chmin(minx, e.first);
    chmin(miny, e.second);
  }
  each(e, v) {
    e.first -= minx;
    e.second -= miny;
  }

  auto [X, Y] = p;

  map<P, vector<P>> g;
  each(e, v) {
    auto [x, y] = e;
    P key;
    if (X == 0) {
      key = P{x, y % Y};
    } else {
      int d = x / X;
      key = P{x % X, y - Y * d};
    }
    g[key].eb(e);
  }
  int ans = 0;
  each(_, v, g) {
    sort(all(v), greater{});
    ans += k;
    rep(i, 1, sz(v)) {
      int dx = v[i - 1].first - v[i].first;
      int dy = v[i - 1].second - v[i].second;
      int d;
      if (X == 0) {
        d = dy / Y;
      } else {
        d = dx / X;
      }
      ans += min(d, k);
    }
  }
  wt(ans);
}
