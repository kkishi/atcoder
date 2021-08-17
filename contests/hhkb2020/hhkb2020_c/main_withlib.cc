#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n);
  Intervals is;
  rep(n) {
    ints(p);
    is.Erase(p, p + 1);
    is.Insert(p, p + 1);
    wt(is.Mex(0));
  }
}
