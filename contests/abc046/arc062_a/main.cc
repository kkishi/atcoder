#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  ints(t, a);
  rep(n - 1) {
    ints(ti, ai);
    int k = max(div_ceil(t, ti), div_ceil(a, ai));
    t = ti * k;
    a = ai * k;
  }
  wt(t + a);
}
