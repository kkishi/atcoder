#include <bits/stdc++.h>

#include "atcoder.h"

int digits(int x) {
  int ret = 0;
  while (x) {
    ++ret;
    x /= 10;
  }
  return ret;
}

void Main() {
  ints(n);
  int ans = 0;
  rep(i, n) if (digits(i + 1) % 2 == 1)++ ans;
  wt(ans);
}
