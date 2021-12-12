#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  rep(q) {
    ints(x);
    wt(a.end() - lower_bound(all(a), x));
  }
}
