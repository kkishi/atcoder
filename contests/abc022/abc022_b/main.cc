#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> s;
  int ans = 0;
  rep(i, n) {
    if (!s.insert(a[i]).second) ++ans;
  }
  wt(ans);
}
