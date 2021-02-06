#include <bits/stdc++.h>

#include "atcoder.h"

// Using i64 TLEs probably because of the slower memory access.
#undef int

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  a.erase(unique(all(a)), a.end());

  set<int> fs;
  each(x, a) {
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        fs.insert(i);
        fs.insert(x / i);
      }
    }
  }
  int ans = 0;
  each(f, fs) {
    if (f > a[0]) break;
    int g = 0;
    each(y, a) {
      if (y % f == 0) {
        g = gcd(g, y / f);
      }
    }
    if (g == 1) ++ans;
  }
  wt(ans);
}
