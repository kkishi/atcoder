#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, d);
  cout << fixed << setprecision(20);
  wt((d == 0 ? n : 2.0 * max(0, n - d)) / (n * n) * (m - 1));
}
