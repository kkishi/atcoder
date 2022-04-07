#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  rep(i, n) if (a[i] >= k) {
    wt(i);
    return;
  }
  wt(-1);
}
