#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  wt(BinarySearch<int>(max(a), 0, [&](int mid) {
    int cuts = 0;
    rep(i, n) cuts += (a[i] - 1) / mid;
    return cuts <= k;
  }));
}
