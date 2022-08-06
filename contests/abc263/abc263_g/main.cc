#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"
#include "binary_search.h"
#include "primes.h"

void Main() {
  V<bool> sieve = Sieve(20000000);
  ints(n);
  VV<int> a(2);
  VV<int> b(2);
  int one = 0;
  rep(n) {
    ints(ai, bi);
    if (ai == 1) {
      one = bi;
      continue;
    }
    int i = even(ai) ? 0 : 1;
    a[i].eb(ai);
    b[i].eb(bi);
  }
  a[1].eb(1);
  b[1].eb(0);

  auto flow = [&](int one) {
    b[1].back() = one;
    int E = sz(a[0]), O = sz(a[1]);
    int s = n, t = s + 1;
    atcoder::mf_graph<int> g(n + 2);
    rep(i, E) g.add_edge(s, i, b[0][i]);
    rep(i, O) g.add_edge(E + i, t, b[1][i]);
    rep(i, E) rep(j, O) {
      if (sieve[a[0][i] + a[1][j]]) {
        g.add_edge(i, E + j, max(b[0][i], b[1][j]));
      }
    }
    return g.flow(s, t);
  };

  if (one == 0) {
    wt(flow(0));
  } else {
    int use;
    if (flow(0) == flow(1)) {
      use = 0;
    } else {
      use = BinarySearch<int>(1, one + 1,
                              [&](int x) { return flow(x - 1) < flow(x); });
    }
    wt(flow(use) + (one - use) / 2);
  }
}
