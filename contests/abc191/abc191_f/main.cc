#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

// Using i64 TLEs probably because of the slower memory access.
#undef int

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  a.erase(unique(all(a)), a.end());

  set<int> fs;
  each(x, a) each(d, Divisors(x)) fs.insert(d);

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
