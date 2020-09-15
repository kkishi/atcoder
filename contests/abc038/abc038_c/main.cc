#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  int j = -1;
  rep(i, n) {
    if (j == -1 || a[i - 1] >= a[i]) {
      j = i;
    }
    ans += i - j + 1;
  }
  wt(ans);
}
