#include <bits/stdc++.h>

#include "atcoder.h"
#include "i128.h"

void Main() {
  V<int> a(64);
  cin >> a;
  i128 ans = 0;
  rep(i, 64) {
    ans <<= 1;
    ans += a[63 - i];
  }
  wt(ans);
}
