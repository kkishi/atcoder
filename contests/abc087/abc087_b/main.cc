#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(A, B, C, d);
  int ans = 0;
  rep(a, A + 1) rep(b, B + 1) rep(c, C + 1) {
    if (a * 500 + b * 100 + c * 50 == d) ++ans;
  }
  wt(ans);
}
