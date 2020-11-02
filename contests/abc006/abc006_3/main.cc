#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  rep(i, n + 1) {
    int x = n - i;      // x = j + k
    int y = m - i * 2;  // y = j * 3 + k * 4
    if (y < 0) continue;
    int k = y - x * 3;
    if (k < 0) continue;
    int j = x - k;
    if (j < 0) continue;
    assert(i + j + k == n);
    assert(i * 2 + j * 3 + k * 4 == m);
    wt(i, j, k);
    return;
  }
  wt(-1, -1, -1);
}
