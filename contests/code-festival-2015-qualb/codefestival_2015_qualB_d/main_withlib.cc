#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n);
  Intervals is;
  rep(i, n) {
    ints(s, c);
    while (c > 0) {
      auto it = is.LowerBound(s);
      if (it != is.end() && it->Contains(s)) {
        s = it->right;
        ++it;
      }
      int m = it == is.end() ? c : min(c, it->left - s);
      is.Insert(s, s + m);
      s += m;
      c -= m;
    }
    wt(s - 1);
  }
}
