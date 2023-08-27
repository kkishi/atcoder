#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  rep(i, n - 1) if (a[i] + 1 != a[i + 1]) {
    wt(a[i] + 1);
    return;
  }
}
