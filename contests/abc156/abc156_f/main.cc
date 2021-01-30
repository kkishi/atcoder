#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, q);
  V<int> d(k);
  cin >> d;
  rep(q) {
    ints(n, x, m);
    --n;
    V<int> e(k);
    int neg = 0;
    rep(i, k) {
      e[i] = d[i] % m;
      if (e[i] == 0) {
        if (n >= i + 1) {
          neg += 1 + (n - (i + 1)) / k;
        }
      }
    }
    int es = accumulate(all(e), int(0));
    int er = accumulate(e.begin(), e.begin() + n % k, int(0));
    int an = x + n / k * es + er;
    neg += an / m - x / m;
    wt(n - neg);
  }
}
