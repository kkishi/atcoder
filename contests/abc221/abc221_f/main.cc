#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int maxi = 0;
  int maxi_n;
  Fix([&](auto rec, int node, int parent, int d) -> void {
    if (maxi < d) {
      maxi = d;
      maxi_n = node;
    }
    each(child, g[node]) if (child != parent) rec(child, node, d + 1);
  })(0, -1, 0);
  V<int> prev(n);
  int maxi2 = 0;
  int maxi2_n;
  Fix([&](auto rec, int node, int parent, int d) -> void {
    if (maxi2 < d) {
      maxi2 = d;
      maxi2_n = node;
    }
    each(child, g[node]) if (child != parent) {
      prev[child] = node;
      rec(child, node, d + 1);
    }
  })(maxi_n, -1, 0);
  int a = maxi_n, b = maxi2_n, d = maxi2;
  V<int> path;
  int i = b;
  while (true) {
    path.pb(i);
    if (i == a) break;
    i = prev[i];
  }
  if (even(d)) {
    int c = d / 2;
    int parent = path[c];
    mint ans = 1;
    mint neg = 1;
    each(child, g[parent]) {
      int cand = Fix([&](auto rec, int node, int parent, int d) -> int {
        int ret = 0;
        if (d == c) ++ret;
        each(child, g[node]) if (child != parent) {
          ret += rec(child, node, d + 1);
        }
        return ret;
      })(child, parent, 1);
      ans *= cand + 1;
      neg += cand;
    }
    ans -= neg;
    wt(ans);
  } else {
    int x = path[d / 2];
    int y = path[d / 2 + 1];
    int c = d / 2;
    auto rec = Fix([&](auto rec, int node, int parent, int d) -> int {
      int ret = 0;
      if (d == c) ++ret;
      each(child, g[node]) if (child != parent) {
        ret += rec(child, node, d + 1);
      }
      return ret;
    });
    mint X = rec(x, y, 0);
    mint Y = rec(y, x, 0);
    wt(X * Y);
  }
}
