#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n);
  Intervals is;
  rep(n) {
    ints(l, r);
    ++r;
    int rem = r - l;
    while (rem > 0) {
      // Erase [l, inf) as much as possible up to rem.
      auto it = is.LowerBound(l);
      if (it == is.end()) break;
      int left = max(l, it->left);
      each(e, is.Erase(left, left + rem)) rem -= e.Length();
    }
    is.Insert(l, r);
  }
  int ans = 0;
  each(e, is) ans += e.Length();
  wt(ans);
}
