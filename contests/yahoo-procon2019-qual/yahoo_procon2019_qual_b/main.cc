#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> c(4);
  rep(3) {
    ints(a, b);
    ++c[a - 1];
    ++c[b - 1];
  }
  sort(c);
  wt((c[0] == 1 && c[1] == 1 && c[2] == 2 && c[3] == 2) ? "YES" : "NO");
}
