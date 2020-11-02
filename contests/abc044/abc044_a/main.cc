#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, x, y);
  wt(x * min(k, n) + y * max(0, n - k));
}
