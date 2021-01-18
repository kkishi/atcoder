#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  each(ai, a)++ m[ai];
  int x = k;
  int ans = 0;
  rep(i, 3 * 100001) {
    int nx = min(m[i], x);
    ans += i * (x - nx);
    x = nx;
  }
  wt(ans);
}
