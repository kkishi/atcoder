#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  strings(s);
  int i = 0;
  rep(q) {
    ints(t, x);
    if (t == 1) {
      i -= x;
      i += n;
      i %= n;
    } else {
      wt(s[(i + x - 1) % n]);
    }
  }
}
