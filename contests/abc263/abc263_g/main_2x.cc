#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"
#include "primes.h"

void Main() {
  V<bool> sieve = Sieve(20000000);
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int s = n * 2, t = s + 1;
  atcoder::mf_graph<int> g(n * 2 + 2);
  rep(i, n) {
    g.add_edge(s, i, b[i]);
    g.add_edge(n + i, t, b[i]);
  }
  rep(i, n) rep(j, n) if (sieve[a[i] + a[j]]) g.add_edge(i, n + j, big);
  wt(g.flow(s, t) / 2);
}
