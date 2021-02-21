#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  int ans = 0;
  rep(a, 1, k + 1) {
    int l = k / a;
    int maxb = 0;
    for (int b = 1; b * b <= l; ++b) {
      chmax(maxb, b);
      int c = l / b;
      ans += c * 2;
    }
    ans -= maxb * maxb;
  }
  wt(ans);
}
