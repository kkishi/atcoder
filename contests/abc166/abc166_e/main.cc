#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  int ans = 0;
  rep(i, n) {
    ans += m[i - a[i]];
    m[i + a[i]]++;
  }
  wt(ans);
}
