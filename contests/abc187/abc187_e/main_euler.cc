#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"
#include "euler_tour.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph<int> g(n);
  V<pair<int, int>> es;
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b);
    g.AddEdge(b, a);
    es.eb(a, b);
  }
  auto [in, out] = EulerTour(g);

  V<int> ans(n);
  DualSegmentTree<int> st(n * 2, [](int a, int b) { return a + b; });
  ints(q);
  rep(q) {
    ints(t, e, x);
    auto [a, b] = es[e - 1];
    if (t == 2) swap(a, b);
    if (in[a] < in[b]) {
      st.Update(0, in[b], x);
      st.Update(out[b], n * 2, x);
    } else {
      st.Update(in[a], out[a], x);
    }
  }
  rep(i, n) wt(st.Get(in[i]));
}
