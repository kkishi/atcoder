#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, x, y);
  int ans = big;
  for (int i = 0; i <= max(x, y); ++i) {
    int sum = i * 2 * c;
    if (x > i) sum += (x - i) * a;
    if (y > i) sum += (y - i) * b;
    chmin(ans, sum);
  }
  wt(ans);
}
