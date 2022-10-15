#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra_generic.h"

void add(int& x, int y, int b) {
  x <<= b;
  x += y;
}

int pop(int& x, int b) {
  int ret = x & ((1 << b) - 1);
  x >>= b;
  return ret;
}

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

  using S = int;
  auto pack = [](int l, int r, int d) -> S {
    S x = 0;
    add(x, l, 16);
    add(x, r, 16);
    add(x, d, 1);
    return x;
  };
  auto unpack = [](S s) -> tuple<int, int, int> {
    int d = pop(s, 1);
    int r = pop(s, 16);
    int l = pop(s, 16);
    return {l, r, d};
  };
  auto spos = [&](S s) {
    auto [l, r, d] = unpack(s);
    return v[(d == 0 ? l : r)];
  };
  unordered_map<S, int> dist =
      Dijkstra<S, int>(pack(init, init, 0), [&](S s, auto push) {
        auto [l, r, d] = unpack(s);
        int pos = spos(s);
        auto check = [&](int ypos) -> bool {
          auto it = ym.find(ypos);
          if (it == ym.end()) return true;
          int zpos = z[it->second];
          return v[l] <= zpos && zpos <= v[r];
        };
        // Go left
        if (l - 1 >= 0) {
          int npos = v[l - 1];
          if (check(npos)) push(pack(l - 1, r, 0), pos - npos);
        }
        // Go right
        if (r + 1 < sz(v)) {
          int npos = v[r + 1];
          if (check(npos)) push(pack(l, r + 1, 1), npos - pos);
        }
      });
  int ans = big;
  each(s, c, dist) if (spos(s) == x) chmin(ans, c);
  if (ans == big) ans = -1;
  wt(ans);
}
