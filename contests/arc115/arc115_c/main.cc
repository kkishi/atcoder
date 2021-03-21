#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  V<set<int>> ng(n);
  rep(i, n) {
    for (int j = 1;; ++j) {
      if (!ng[i].count(j)) {
        a[i] = j;
        break;
      }
    }
    int I = i + 1;
    for (int J = I * 2; J <= n; J += I) {
      ng[J - 1].insert(a[i]);
    }
  }
  wt(a);
}
