#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  each(e, c)-- e;
  VV<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b);
    g[b].eb(a);
  }
  V<int> complementary(n);
  using M = map<int, int>;
  struct Result {
    int size_all;
    M size_color;
  };
  auto merge = [&](M& a, M& b) {
    if (sz(a) < sz(b)) swap(a, b);
    each(k, v, b) a[k] += v;
  };
  auto calc = [](int x) { return x * (x - 1) / 2 + x; };
  Fix([&](auto rec, int node, int parent) -> Result {
    const int col = c[node];
    Result ret;
    ret.size_all = 1;
    each(child, g[node]) if (child != parent) {
      Result res = rec(child, node);
      complementary[col] += calc(res.size_all - res.size_color[col]);
      ret.size_all += res.size_all;
      merge(ret.size_color, res.size_color);
    }
    ret.size_color[col] = ret.size_all;
    if (parent == -1) {
      rep(i, n) if (i != col) complementary[i] += calc(n - ret.size_color[i]);
    }
    return ret;
  })(0, -1);

  int tot = calc(n);
  rep(i, n) wt(tot - complementary[i]);
}
