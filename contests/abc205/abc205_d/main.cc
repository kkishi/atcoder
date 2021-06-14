#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  a.pb(big);
  int N = n + 1;
  rep(q) {
    ints(k);
    int x = BinarySearch<int>(N - 1, -1, [&](int x) {
      int y = a[x] - (x + 1);
      return y >= k;
    });
    int y = a[x] - (x + 1);
    wt(a[x] - (y - k + 1));
  }
}
