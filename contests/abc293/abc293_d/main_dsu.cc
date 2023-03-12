#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  int total = n;
  int loop = 0;
  rep(m) {
    ints(a);
    --a;
    rd(char, b);
    ints(c);
    --c;
    rd(char, d);
    if (ds.Same(a, c)) {
      ++loop;
    } else {
      ds.Union(a, c);
      --total;
    }
  }
  wt(loop, total - loop);
}
