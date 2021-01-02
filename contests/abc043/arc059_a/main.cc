#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = big;
  rep(i, -100, 101) {
    int sum = 0;
#define sq(x) ((x) * (x))
    rep(j, n) sum += sq(a[j] - i);
    chmin(ans, sum);
  }
  wt(ans);
}
