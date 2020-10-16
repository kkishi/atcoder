#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, x);
  int ans = b / x;
  if (a == 0) {
    ++ans;
  } else {
    ans -= (a - 1) / x;
  }
  wt(ans);
}
