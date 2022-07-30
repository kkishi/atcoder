#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int x = abs(a - b);
  int ans = x / 10;
  x %= 10;
  if (x >= 5) {
    ans += min(x - 4, 11 - x);
  } else {
    ans += min(x, 6 - x);
  }
  wt(ans);
}
