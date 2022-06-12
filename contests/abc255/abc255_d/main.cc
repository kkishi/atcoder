#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  sort(a);
  V<int> s = a;
  rep(i, 1, n) s[i] += s[i - 1];
  rep(q) {
    ints(x);
    if (a[0] >= x) {
      wt(s[n - 1] - x * n);
    } else if (a[n - 1] <= x) {
      wt(x * n - s[n - 1]);
    } else {
      int i = BinarySearch<int>(0, n, [&](int i) { return a[i] < x; });
      wt(x * (i + 1) - s[i] + (s[n - 1] - s[i]) - x * (n - 1 - i));
    }
  }
}
