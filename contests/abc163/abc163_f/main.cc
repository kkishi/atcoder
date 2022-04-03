#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "euler_tour.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  each(e, c)-- e;
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b);
    g.AddEdge(b, a);
  }
  auto [in, out] = EulerTour(g);
  VV<int> v(n);
  rep(i, n) v[c[i]].eb(i);
  AddSegmentTree<int> t(n);
  auto calc = [](int x) { return x * (x + 1) / 2; };
  auto size = [&](int i) {
    return out[i] - in[i] - t.Aggregate(in[i], out[i]);
  };
  rep(col, n) {
    V<int>& vi = v[col];
    sort(vi, [&](int i, int j) { return in[i] > in[j]; });
    int ans = calc(n);
    each(i, vi) {
      each(e, g.Edges(i)) if (in[e.to] > in[i]) ans -= calc(size(e.to));
      t.Set(in[i], size(i));
    }
    ans -= calc(size(0));
    wt(ans);
    each(i, vi) t.Set(in[i], 0);
  }
}
