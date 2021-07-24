#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> v;
  rep(m) {
    ints(a, c);
    v.eb(c, a);
  }
  sort(all(v));
  int ans = 0;
  each(c, a, v) {
    if (n == 1) break;
    int g = gcd(n, a);
    if (g == 1) {
      ans += c * (n - 1);
      n = 1;
      break;
    }
    int num_loop = g;
    int per_loop = n / g;
    ans += c * num_loop * (per_loop - 1);
    n = num_loop;
  }
  if (n == 1) {
    wt(ans);
  } else {
    wt(-1);
  }
}
