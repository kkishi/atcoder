#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v(1000001);
  rep(n) {
    ints(a, b);
    ++v[a];
    --v[b + 1];
  }
  int ans = -1, curr = 0;
  rep(i, 1000001) {
    curr += v[i];
    chmax(ans, curr);
  }
  wt(ans);
}
