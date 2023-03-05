#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(i, 1, n) {
    auto cnt = [](int i) {
      int x = 0;
      for (int a = 1; a * a <= i; ++a) {
        if (i % a == 0) {
          ++x;
          if (a * a != i) ++x;
        }
      }
      return x;
    };
    ans += cnt(i) * cnt(n - i);
  }
  wt(ans);
}
