#include <bits/stdc++.h>

#include "atcoder.h"
#undef int
#include "bignum.h"
#define int i64

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  bigint ans = 1;
  bigint ten = 1;
  bigint sum = 0;
  rep(i, n) {
    if (sum < ten) {
      ans *= sum + 1;
      sum = 0;
      ten = 1;
    }
    sum += ten * a[i];
    ten *= 10;
  }
  wt((ans * (sum + 1) - 1) % 1000000007);
}
