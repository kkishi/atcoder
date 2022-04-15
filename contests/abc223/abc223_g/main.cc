#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "mermaid.h"
#include "rerooting.h"

struct T {
  int w;   // With excess node
  int wo;  // Without excess node
};

namespace std {
ostream& operator<<(ostream& os, const T& t) {
  os << "[" << t.w << " " << t.wo << "]";
  return os;
}
}  // namespace std

void Main() {
  ints(n);
  V<pair<int, int>> v(n - 1);
  cin >> v;
  each(a, b, v)-- a, --b;

  BidirectedGraph<int> g(n);
  each(a, b, v) g.AddEdge(a, b);

  auto merge = [](T a, T b) -> T {
    T c = {max(a.w, b.w), max(a.wo, b.wo)};
    if (a.w >= 0) chmax(c.w, a.w + b.wo);
    if (b.w >= 0) chmax(c.w, b.w + a.wo);
    chmax(c.wo, a.wo + b.wo);
    return c;
  };

  auto add_node = [](const auto&, T x) -> T {
    T y = {0, -1};
    chmax(y.w, x.wo);
    if (x.w >= 0) {
      chmax(y.w, x.w);
      chmax(y.wo, x.w + 1);
    }
    return y;
  };

  pclib::internal::DP<T, int> dp(g, merge, add_node, {-1, -1});
  dp.Dfs(0);
  V<T> res = dp.Rerooting(0);
  dbg(res);

  mermaid::Flowchart fc;
  rep(i, n) fc.Node(i, res[i]);
  rep(i, n) each(e, dp.graph_.Edges(i)) {
    fc.Edge(e->from, e->to, e->weight.result);
  }
  fc.WriteTo("/home/keisuke/misc/flowchart.mmd");

  int ma = -big;
  each(e, res) chmax(ma, max(e.w + 1, e.wo));
  int ans = 0;
  each(e, res) if (max(e.w, e.wo) == ma)++ ans;
  wt(ans);
}
