#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] += s[i] + a[i];
  int ans = 0;
  int pos = 0;
  int maxi = 0;
  rep(i, n) {
    chmax(maxi, s[i + 1]);
    chmax(ans, pos + maxi);
    pos += s[i + 1];
  }
  wt(ans);
}
