#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "bit.h"

void Main() {
  ints(n, l);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  wt(BinarySearch<int>(0, l + 1, [&](int x) {
    BIT<int> b(n + 1);
    int lo = 0, hi = 0;
    rep(i, n) {
      while (s[i + 1] - s[lo] > l) ++lo;
      while (s[i + 1] - s[hi] >= x) ++hi;
      bool ok;
      if (lo == 0) {
        ok = s[i + 1] >= x;
      } else {
        ok = b.Sum(hi - 1) - b.Sum(lo - 1) > 0;
      }
      if (ok) b.Set(i + 1, 1);
    }
    return b.Get(n) == 1;
  }));
}
