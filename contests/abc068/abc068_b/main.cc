#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0, x = 1;
  while (x * 2 <= n) {
    x *= 2;
    ++ans;
  }
  wt(x);
}
