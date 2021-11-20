#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  --x;
  int ans = 0;
  set<int> seen;
  while (!seen.count(x)) {
    ++ans;
    seen.insert(x);
    x = a[x] - 1;
  }
  wt(ans);
}
