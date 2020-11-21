#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int mini = numeric_limits<int>::max();
  int tot = 0;
  rep(n) {
    ints(a, b);
    tot += a;
    if (a > b) chmin(mini, b);
  }
  if (mini == numeric_limits<int>::max()) {
    wt(0);
  } else {
    wt(tot - mini);
  }
}
