#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  int ma = -big;
  each(c, g[0]) chmax(ma, Fix([&](auto rec, int n, int p) -> int {
                        int ret = 1;
                        each(c, g[n]) if (c != p) ret += rec(c, n);
                        return ret;
                      })(c, 0));
  wt(n - ma);
}
