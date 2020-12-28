#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> a(n), b(n);
  cin >> a >> b;
  sort(all(a));
  sort(all(b));
  wt(BinarySearch<int>(a.back() * b.back(), 0, [&](int x) {
    int cnt = 0;
    rep(i, n) cnt += lower_bound(all(b), x / a[i] + 1) - b.begin();
    return cnt >= k;
  }));
}
