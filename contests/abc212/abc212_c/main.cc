#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  sort(b);
  int ans = big;
  each(e, a) {
    auto it = lower_bound(all(b), e);
    if (it != b.end()) chmin(ans, abs(e - *it));
    if (it != b.begin()) chmin(ans, abs(e - *prev(it)));
  }
  wt(ans);
}
