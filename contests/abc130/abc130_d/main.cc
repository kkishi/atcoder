#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  int ans = 0;
  rep(i, n) {
    int j = lower_bound(all(s), s[i + 1] - k + 1) - s.begin();
    ans += j;
  }
  wt(ans);
}
