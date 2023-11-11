#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(i, 1, n+1) {
    ints(d);
    rep (j, 1, d+1) {
      auto check = [](int a, int b) {
        while (a) {
          if (a % 10 != b) return false;
          a /= 10;
        }
        return true;
      };
      if (check(i, i % 10) && check(j, i % 10)) ++ans;
    }
  }
  wt(ans);
}
