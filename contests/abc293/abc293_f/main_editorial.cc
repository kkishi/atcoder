#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    if (n == 2) {
      wt(1);
      continue;
    }
    set<int> st = {n - 1, n};
    rep(d, 3, 40) {
      int b = BinarySearch<int>(2, n + 1, [&](int b) {
        __int128 p = 1;
        rep(d - 1) {
          p *= b;
          if (p > n) return false;
        }
        return true;
      });
      int m = n;
      bool ok = true;
      while (m) {
        if (m % b >= 2) ok = false;
        m /= b;
      }
      if (ok) st.insert(b);
    }
    wt(sz(st));
  }
}
