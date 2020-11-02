#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, d);
  auto close = [&d](int a, int b) { return abs(a - b) <= d; };
  wt(close(a, c) || (close(a, b) && close(b, c)));
}
