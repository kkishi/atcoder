#include <bits/stdc++.h>

#include "atcoder.h"
#include "twosets.h"

void Main() {
  ints(n, k);
  V<pair<int, int>> v(n);
  cin >> v;
  reverse(v);
  v.eb(1, 0);

  int ans = -big;
  TwoSets ts;
  int rem = k;
  int sum = 0;
  each(t, y, v) {
    if (t == 1) {
      if (rem >= 0) {
        ts.Adjust(min(rem, ts.Size()));
        chmax(ans, y + sum - ts.LSum());
      }
      --rem;
    } else {
      sum += y;
      if (y < 0) ts.Add(y);
    }
  }
  wt(ans);
}
