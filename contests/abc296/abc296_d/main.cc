#include <bits/stdc++.h>

#include "atcoder.h"
#include "i128.h"

void Main() {
  ints(n, m);
  if (i128(n) * n < m) {
    wt(-1);
  } else {
    rep(i, 1000000) {
      int M = m + i;
      for (int j = max(1, M / n); j * j <= M; ++j) {
        if (M % j == 0) {
          int k = M / j;
          if (j <= n && k <= n) {
            wt(M);
            return;
          }
        }
      }
    }
  }
}
