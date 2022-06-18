#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n);
  Intervals is;
  rep(n) {
    ints(l, r);
    is.Erase(l, r);
    is.Insert(l, r);
  }
  each(e, is) wt(e.left, e.right);
}
