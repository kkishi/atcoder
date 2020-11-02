#include <bits/stdc++.h>

#include "atcoder.h"
#undef int
#include "bignum.h"
#define int i64

void Main() {
  ints(n);
  V<bigint> a(n);
  cin >> a;
  if (find(all(a), 0) != a.end()) {
    wt(0);
    return;
  }
  bigint ans = 1;
  rep(i, n) {
    ans *= a[i];
    if (ans > 1000000000000000000) {
      wt(-1);
      return;
    }
  }
  wt(ans);
}
