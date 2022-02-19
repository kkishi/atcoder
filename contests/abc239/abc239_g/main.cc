#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(n, m);
  atcoder::mf_graph<int> g(n * 2);
#define I(x) (x)
#define O(x) ((x) + n)
  rep(m) {
    ints(a, b);
    --a, --b;
    g.add_edge(O(a), I(b), big);
    g.add_edge(O(b), I(a), big);
  }
  V<int> c(n);
  cin >> c;
  rep(i, n) g.add_edge(I(i), O(i), c[i]);
  wt(g.flow(O(0), I(n - 1)));
  V<bool> mc = g.min_cut(O(0));
  V<int> ans;
  rep(i, n) if (mc[I(i)] && !mc[O(i)]) ans.pb(i + 1);
  wt(sz(ans));
  wt(ans);
}
