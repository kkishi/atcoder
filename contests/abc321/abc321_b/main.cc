#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n - 1);
  cin >> a;
  rep(i, 101) {
    V<int> b = a;
    b.eb(i);
    sort(b);
    int sum = accumulate(b) - min(b) - max(b);
    if (sum >= x) {
      wt(i);
      return;
    }
  }
  wt(-1);
}
