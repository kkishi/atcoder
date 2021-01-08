#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int mini = big;
  int tot = 0;
  rep(n) {
    ints(a, b);
    tot += a;
    if (a > b) chmin(mini, b);
  }
  if (mini == big) {
    wt(0);
  } else {
    wt(tot - mini);
  }
}
