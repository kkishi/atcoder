#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"
#include "rand.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  Rand r;
  int ans = -1;
  rep(100) {
    int i = r.Int(0, n - 1);
    int j = r.Int(0, n - 1);
    if (i == j) continue;
    each(d, Divisors(abs(a[i] - a[j]))) {
      if (3 <= d) {
        int cnt = 0;
        rep(k, n) if (a[k] % d == a[i] % d)++ cnt;
        if (cnt * 2 > n) ans = d;
      }
    }
  }
  wt(ans);
}
