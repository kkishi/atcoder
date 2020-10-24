#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  double x = 6.0 * (k - 1) * (n - k);
  double y = 3.0 * (n - 1);
  double z = 1.0;
  wt((x + y + z) / (n * n * n));
}
