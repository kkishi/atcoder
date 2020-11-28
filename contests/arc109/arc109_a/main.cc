#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, x, y);
  int ans = x;
  if (a > b) {
    --a;
  }
  int c = abs(a - b);
  if (x * 2 < y) {
    ans += x * 2 * c;
  } else {
    ans += y * c;
  }
  wt(ans);
}
