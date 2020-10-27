#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  if (n <= 2) {
    if (m != 0) {
      wt(-1);
    } else {
      rep(i, n) wt(i * 2 + 1, i * 2 + 2);
    }
    return;
  }
  if (m < 0 || m > n - 2) {
    wt(-1);
    return;
  }
  if (m == 0) {
    rep(i, n) wt(i * 2 + 1, i * 2 + 2);
    return;
  }
  rep(i, n - 1) wt(i * 3 + 2, i * 3 + 3);
  wt(1, 4 + 3 * m);
}
