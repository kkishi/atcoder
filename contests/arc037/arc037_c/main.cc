#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "count.h"

void Main() {
  ints(n, k);
  V<int> a(n), b(n);
  cin >> a >> b;
  sort(a);
  sort(b);
  wt(BinarySearch<int>(a.back() * b.back(), 0, [&](int x) {
    int cnt = 0;
    rep(i, n) cnt += CountLE(b, x / a[i]);
    return cnt >= k;
  }));
}
