#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(q);
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(k, x);
      a[k - 1] = x;
    } else {
      ints(k);
      wt(a[k - 1]);
    }
  }
}
