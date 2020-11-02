#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  ints(t, a);
  rep(n - 1) {
    ints(ti, ai);
    int k = max((t + ti - 1) / ti, (a + ai - 1) / ai);
    t = ti * k;
    a = ai * k;
  }
  wt(t + a);
}
