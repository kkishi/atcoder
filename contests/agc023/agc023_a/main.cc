#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  m[0] = 1;
  int ans = 0;
  int s = 0;
  rep(i, n) {
    s += a[i];
    ans += m[s];
    ++m[s];
  }
  wt(ans);
}
