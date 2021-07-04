#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(n, w);
  V<int> a(n);
  cin >> a;
  atcoder::mf_graph<int> g(n + 2);
  int s = n, t = n + 1;
  int ans = 0;
  rep(i, n) {
    int x = a[i] - w;
    if (x < 0) {
      g.add_edge(s, i, -x);
      g.add_edge(i, t, 0);
    } else {
      ans += x;
      g.add_edge(s, i, 0);
      g.add_edge(i, t, x);
    }
    ints(k);
    rep(k) {
      ints(c);
      g.add_edge(i, c - 1, big);
    }
  }
  wt(ans - g.flow(s, t));
}
