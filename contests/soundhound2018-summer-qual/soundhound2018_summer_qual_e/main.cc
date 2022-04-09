#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  g.Read(m);

  auto check = [&](int x0) {
    V<int> val(n, -1);
    return Fix([&](auto rec, int node, int x) -> bool {
      if (val[node] != -1) {
        return val[node] == x;
      }
      val[node] = x;
      each(child, w, g[node]) {
        if (w <= x) return false;
        if (!rec(child, w - x)) return false;
      }
      return true;
    })(0, x0);
  };

  V<bool> seen(n);
  V<int> sign(n);
  V<int> val(n);
  int mi = -big;
  int ma = big;
  Fix([&](auto rec, int node, int s, int v) {
    if (s == 1) {
      chmax(mi, -v + 1);
    } else {
      chmin(ma, v - 1);
    }
    if (seen[node]) {
      if (sign[node] == s && val[node] == v) return;
      if (sign[node] != s) {
        int v0 = val[node];
        int v1 = v;
        if (sign[node] == -1) {
          swap(v0, v1);
        }
        // x + v0 = -x + v1
        // x = (v1 - v0) / 2
        int x2 = v1 - v0;
        if (x2 > 0 && even(x2)) {
          int x = x2 / 2;
          wt(int(check(x)));
          exit(0);
        }
      }
      wt(0);
      exit(0);
    }
    seen[node] = true;
    sign[node] = s;
    val[node] = v;
    each(child, w, g[node]) rec(child, -s, w - v);
  })(0, 1, 0);

  int ans = max(0, ma - mi + 1);
  if (ans > 0) {
    assert(check(mi));
    assert(check(ma));
  }
  wt(ans);
}
