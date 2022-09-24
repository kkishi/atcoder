#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int x = BinarySearch<int>(0, k + 1, [&](int x) -> bool {
    int sum = 0;
    each(e, a) sum += min(e, x);
    return sum <= k;
  });
  int sum = 0;
  each(e, a) {
    int y = min(e, x);
    e -= y;
    sum += y;
  }
  rep(i, n) if (sum < k && a[i] > 0) {
    ++sum;
    --a[i];
  }
  wt(a);
}
