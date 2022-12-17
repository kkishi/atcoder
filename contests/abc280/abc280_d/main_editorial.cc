#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(k);
  int ans = -big;
  each(k, v, Factors(k)) {
    int cnt = 0;
    for (int i = 1;; ++i) {
      int I = i * k;
      while (I % k == 0) {
        I /= k;
        ++cnt;
      }
      if (cnt >= v) {
        chmax(ans, i * k);
        break;
      }
    }
  }
  wt(ans);
}
