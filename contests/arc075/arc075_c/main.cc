#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"
#include "compressor.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  V<int> b(n + 1);
  rep(i, 1, n + 1) b[i] = s[i] - k * i;
  Compressor cb(b);
  BIT<int> bit(sz(cb.coord));
  int ans = 0;
  rep(i, n + 1) {
    int j = cb(b[i]);
    ans += bit.Sum(j);
    bit.Add(j, 1);
  }
  wt(ans);
}
