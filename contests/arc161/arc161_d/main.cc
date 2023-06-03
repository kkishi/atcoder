#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  if (d * 2 <= n - 1) {
    wt("Yes");
    rep(i, n) rep(j, d) wt(i + 1, (i + j + 1) % n + 1);
  } else {
    wt("No");
  }
}
