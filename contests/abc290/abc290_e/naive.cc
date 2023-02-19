#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) {
    int I = i, J = j;
    while (I < J) {
      if (a[I] != a[J]) ++ans;
      ++I, --J;
    }
  }
  wt(ans);
}
