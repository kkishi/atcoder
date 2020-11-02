#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  V<int> x;
  rrep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      x.push_back(a[i]);
      --i;
      if (x.size() == 2) {
        wt(x[0] * x[1]);
        return;
      }
    }
  }
  wt(0);
}
