#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, w);
  V<int> inc(200001);
  rep(n) {
    ints(s, t, p);
    inc[s] += p;
    inc[t] -= p;
  }
  rep(i, sz(inc) - 1) inc[i + 1] += inc[i];
  bool ok = true;
  rep(i, sz(inc)) if (inc[i] > w) ok = false;
  wt(ok);
}
