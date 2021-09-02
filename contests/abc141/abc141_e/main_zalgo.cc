#include <bits/stdc++.h>

#include "atcoder.h"
#include "z_algorithm.h"

void Main() {
  ints(n);
  strings(s);
  int ans = 0;
  rep(i, n) {
    auto z = ZAlgorithm(s.substr(i));
    rep(j, i + 1, n) chmax(ans, min(j - i, z[j - i]));
  }
  wt(ans);
}
