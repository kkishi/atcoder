#include <bits/stdc++.h>

#include "atcoder.h"

int solve(int n, int m) {
  if (n == 1 && m == 1) return 1;
  if (n == 1 || m == 1) return max(n, m) - 2;
  return (n - 2) * (m - 2);
}

void Main() {
  ints(n, m);
  wt(solve(n, m));
}
