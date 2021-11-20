#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> sum(n);
  rep(i, n) rep(3) {
    ints(p);
    sum[i] += p;
  }
  V<int> v(all(sum));
  sort(all(v));
  rep(i, n) wt((v.end() - lower_bound(all(v), sum[i] + 301)) < k);
}
