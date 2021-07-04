#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(n);
  atcoder::mf_graph<int> g(n + 2);
  int s = 0, t = n + 1;
  int sum = 0;
  rep(i, 1, n + 1) {
    ints(a);
    if (a > 0) {
      sum += a;
      g.add_edge(s, i, 0);
      g.add_edge(i, t, a);
    } else {
      g.add_edge(s, i, -a);
      g.add_edge(i, t, 0);
    }
    for (int j = i * 2; j <= n; j += i) {
      g.add_edge(i, j, big);
    }
  }
  wt(sum - g.flow(s, t));
}
