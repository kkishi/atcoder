#include <bits/stdc++.h>

#include <atcoder/mincostflow>

#include "atcoder.h"
#include "primes.h"

void Main() {
  V<bool> sieve = Sieve(20000000);
  ints(n);
  VV<int> a(2);
  VV<int> b(2);
  int one = 0;
  rep(n) {
    ints(ai, bi);
    if (ai == 1) one = bi;
    int i = even(ai) ? 0 : 1;
    a[i].eb(ai);
    b[i].eb(bi);
  }

  int E = sz(a[0]), O = sz(a[1]);
  int s = n, t = s + 1;
  atcoder::mcf_graph<int, int> g(n + 2);
  rep(i, E) g.add_edge(s, i, b[0][i], 0);
  rep(i, O) g.add_edge(E + i, t, b[1][i], a[1][i] == 1);
  rep(i, E) rep(j, O) {
    if (sieve[a[0][i] + a[1][j]]) {
      g.add_edge(i, E + j, big, 0);
    }
  }
  auto [flow, cost] = g.flow(s, t);
  wt(flow + (one - cost) / 2);
}
