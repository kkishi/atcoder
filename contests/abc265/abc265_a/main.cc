#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, n);
  chmin(y, x * 3);
  wt(n % 3 * x + n / 3 * y);
}
