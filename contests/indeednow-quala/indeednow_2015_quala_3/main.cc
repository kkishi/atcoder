#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "bit.h"

void Main() {
  ints(n);
  V<int> s(n);
  cin >> s;
  BIT<int> bit(1000001);
  rep(i, n) if (s[i] > 0) bit.Add(s[i], 1);
  ints(q);
  rep(q) {
    ints(k);
    if (k >= bit.Sum(1000000)) {
      wt(0);
      continue;
    }
    wt(BinarySearch<int>(1000001, 0, [&](int x) {
      return bit.Sum(1000000) - bit.Sum(x - 1) <= k;
    }));
  }
}
