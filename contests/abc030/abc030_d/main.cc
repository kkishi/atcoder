#include <bits/stdc++.h>

#include "atcoder.h"
#undef int
#include "bignum.h"

void Main() {
  ints(n, a);
  rd(bigint, k);
  --a;
  V<int> b(n);
  cin >> b;
  V<int> seen(n, -1);
  seen[a] = 0;
  for (int step = 1; step <= k; ++step) {
    a = b[a] - 1;
    if (seen[a] != -1) {
      int dist = step - seen[a];
      int x = int((k - step) % dist);
      rep(i, x) a = b[a] - 1;
      break;
    }
    seen[a] = step;
  }
  wt(a + 1);
}
