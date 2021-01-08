#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, k);
  const int nichou = 2000000000000LL;
  if (k == 0) {
    wt(nichou - a);
    return;
  }
  int ans = 0;
  while (a < nichou) {
    a += 1 + k * a;
    ++ans;
  }
  wt(ans);
}
