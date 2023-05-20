#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, d);
  V<int> a(n), b(m);
  cin >> a >> b;
  sort(a);
  sort(b);
  int ans = -1;
  each(e, a) {
    auto it = lower_bound(all(b), e + d + 1);
    if (it == b.begin()) continue;
    int f = *prev(it);
    if (f >= e - d) chmax(ans, e + f);
  }
  wt(ans);
}
