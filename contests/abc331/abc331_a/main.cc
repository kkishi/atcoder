#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(M, D);
  ints(y, m, d);
  ++d;
  if (d > D) {
    d = 1;
    ++m;
    if (m > M) {
      m = 1;
      ++y;
    }
  }
  wt(y, m, d);
}
