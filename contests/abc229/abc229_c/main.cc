#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, w);
  V<pair<int, int>> v;
  rep(n) {
    ints(a, b);
    v.eb(a, b);
  }
  sort(all(v), greater{});
  int ans = 0;
  each(a, b, v) {
    int c = min(b, w);
    w -= c;
    ans += a * c;
  }
  wt(ans);
}
