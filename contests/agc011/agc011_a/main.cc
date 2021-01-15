#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, c, k);
  V<int> t(n);
  cin >> t;
  sort(all(t));
  int ans = 0;
  int start = -big;
  int cnt = 0;
  rep(i, n) {
    if (t[i] - start > k || cnt == c) {
      ++ans;
      start = t[i];
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  wt(ans);
}
