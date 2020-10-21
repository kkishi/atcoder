#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, h, n);
  rep(n) {
    ints(a);
    if (a < l) {
      wt(l - a);
    } else if (h < a) {
      wt(-1);
    } else {
      wt(0);
    }
  }
}
