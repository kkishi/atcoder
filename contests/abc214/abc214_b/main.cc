#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(s, t);
  int ans = 0;
  rep(a, s + 1) rep(b, s + 1) rep(c, s + 1) {
    if (a + b + c <= s && a * b * c <= t) ++ans;
  }
  wt(ans);
}
