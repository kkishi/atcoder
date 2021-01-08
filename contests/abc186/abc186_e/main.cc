#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"

using namespace atcoder;

int Solve() {
  ints(n, s, k);
  V<long long> r{n - s, 0};
  V<long long> m{n, k};
  auto [y, z] = crt(r, m);
  if (y == 0) {
    return -1;
  } else {
    return y / k;
  }
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
