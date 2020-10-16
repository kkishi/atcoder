#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  int sum = 0;
  int x = 7;
  rep(i, k + 1) {
    sum = (sum + x) % k;
    if (sum == 0) {
      wt(i + 1);
      return;
    }
    x = x * 10 % k;
  }
  wt(-1);
}
