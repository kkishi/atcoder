#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  int s = 0;
  rep(q) {
    ints(t, x, y);
    --x, --y;
    auto rot = [&](int x) { return (x + s) % n; };
    if (t == 1) {
      swap(a[rot(x)], a[rot(y)]);
    } else if (t == 2) {
      --s;
      if (s < 0) s += n;
    } else {
      wt(a[rot(x)]);
    }
  }
}
