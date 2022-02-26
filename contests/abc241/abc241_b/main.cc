#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, m);
    map<int, int> M;
    rep(n) {
      ints(a);
      ++M[a];
    }
    rep(m) {
      ints(b);
      if (--M[b] < 0) {
        return false;
      }
    }
    return true;
  }());
}
