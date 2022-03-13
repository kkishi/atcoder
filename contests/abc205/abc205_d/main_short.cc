#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  sort(a);
  a.erase(unique(all(a)), a.end());
  a.pb(big);
  rep(q) {
    ints(k);
    wt(BinarySearch<int>(n, -1, [&](int x) { return a[x] - x > k; }) + k);
  }
}
