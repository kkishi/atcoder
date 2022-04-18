#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n, k);
  V<int> sum(n);
  rep(i, n) rep(3) {
    ints(p);
    sum[i] += p;
  }
  V<int> v = sum;
  sort(v);
  rep(i, n) wt(CountGT(v, sum[i] + 300) < k);
}
