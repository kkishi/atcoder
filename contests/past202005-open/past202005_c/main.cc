#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, r, n);
  int large = 1000000000;
  if (r == 1) {
    if (a > large) {
      wt("large");
    } else {
      wt(a);
    }
  } else {
    rep(n - 1) {
      a *= r;
      if (a > large) {
        wt("large");
        return;
      }
    }
    wt(a);
  }
}
