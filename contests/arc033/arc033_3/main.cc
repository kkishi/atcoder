#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "bit.h"

void Main() {
  ints(q);
  BIT<int> bit(200001);
  rep(q) {
    ints(t, x);
    if (t == 1) {
      bit.Add(x, 1);
    } else {
      int y =
          BinarySearch<int>(200001, 0, [&](int y) { return bit.Sum(y) >= x; });
      wt(y);
      bit.Add(y, -1);
    }
  }
}
