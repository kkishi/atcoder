#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    int ans = 0;
    rep(i, 2, n + 1) {
      int j = n;
      bool ok = true;
      while (j) {
        if (j % i >= 2) ok = false;
        j /= i;
      }
      if (ok) ++ans;
    }
    wt(ans);
  }
}
