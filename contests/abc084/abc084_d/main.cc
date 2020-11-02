#include <bits/stdc++.h>

#include "atcoder.h"
#include "prime.h"

void Main() {
  V<bool> s = Sieve(100000);
  V<int> sum(100001);
  rep(i, 1, 100001) {
    sum[i] = sum[i - 1];
    if (i & 1 && s[i] && s[(i + 1) / 2]) {
      ++sum[i];
    }
  }
  ints(q);
  rep(q) {
    ints(l, r);
    wt(sum[r] - sum[l - 1]);
  }
}
