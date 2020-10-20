#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> s(n);
  cin >> s;
  if (count(all(s), 0)) {
    wt(n);
    return;
  }
  int ans = 0;
  int l = 0, p = 1;
  rep(i, n) {
    p *= s[i];
    while (p > k && l <= i) {
      p /= s[l];
      ++l;
    }
    if (l <= i) chmax(ans, i - l + 1);
  }
  wt(ans);
}
