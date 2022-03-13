#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(n);

  V<pair<int, int>> bs;
  rep(i, n) {
    ints(b);
    bs.eb(b - 1, i);
  }
  sort(bs, greater{});

  int ans = 0;
  BIT<int> bit(n);
  for (auto [b, i] : bs) {
    ans += min(bit.Sum(i - 1), bit.Sum(n - 1) - bit.Sum(i));
    bit.Add(i, 1);
  }
  wt(ans);
}
