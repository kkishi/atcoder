#include <bits/stdc++.h>

#include "atcoder.h"

using P = pair<int, int>;

int Area8(P a, P b, P c) {
  auto [x1, y1] = a;
  auto [x2, y2] = b;
  auto [x3, y3] = c;
  return 4 * ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
}

void Main() {
  ints(n);
  V<P> p;
  rep(n) {
    ints(x, y);
    p.eb(x, y);
  }
  int tot = 0;
  rep(i, 1, n - 1) tot += Area8(p[0], p[i], p[i + 1]);

  int ans = big;
  int i = 0;
  int j = 1;
  int sum = 0;
  rep(n) {
    auto nex = [&](int i) { return (i + 1) % n; };
    while (true) {
      int a = Area8(p[i], p[j], p[nex(j)]);
      if (sum + a >= tot / 4) {
        chmin(ans, abs(sum - tot / 4));
        chmin(ans, abs(sum + a - tot / 4));
        break;
      }
      sum += a;
      j = nex(j);
    }
    if (j == nex(i)) {
      j = nex(j);
    } else {
      sum -= Area8(p[i], p[nex(i)], p[j]);
    }
    i = nex(i);
  }
  wt(ans);
}
