#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> t(n);
  cin >> t;
  int sum = reduce(all(t));
  ints(m);
  rep(i, m) {
    ints(p, x);
    wt(sum - t[p - 1] + x);
  }
}
