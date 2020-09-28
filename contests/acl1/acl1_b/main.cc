#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"
#include "factorize.h"

void Main() {
  ints(n);
  n *= 2;
  map<int, int> fs = Factorize(n);

  int ans = numeric_limits<int>::max();
  Fix([&](auto dfs, map<int, int>::iterator it, int x) {
    if (it == fs.end()) {
      int y = n / x;
      V<long long> r = {0, -1}, m = {x, y};
      if (long long f = atcoder::crt(r, m).first; f != 0) {
        chmin(ans, f);
      }
      return;
    }
    rep(it->second + 1) {
      dfs(next(it), x);
      x *= it->first;
    }
  })(fs.begin(), 1);
  wt(ans);
}
