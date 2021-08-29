#include <bits/stdc++.h>

#include "atcoder.h"
#include "numeric_sequence.h"

void Main() {
  ints(n, k);
  map<int, int> m;
  rep(n) {
    ints(a);
    ++m[a];
  }
  int ans = 0;
  while (k && !m.empty()) {
    auto ma = prev(m.end());
    auto [x, y] = *ma;
    int sx = 0;
    auto sma = m.end();
    if (ma != m.begin()) {
      sma = prev(ma);
      sx = sma->first;
    }
    int dk = (x - sx) * y;
    if (dk <= k) {
      ans += ArithmeticProgressionSum<int>(x, -1, x - sx) * y;
      m.erase(ma);
      sma->second += y;
      k -= dk;
    } else {
      int dx = k / y;
      ans += ArithmeticProgressionSum<int>(x, -1, dx) * y + (k % y) * (x - dx);
      k = 0;
    }
  }
  wt(ans);
}
