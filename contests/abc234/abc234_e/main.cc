#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x);
  string s = to_string(x);
  each(e, s) e -= '0';
  int n = sz(s);
  if (n <= 2) {
    wt(x);
    return;
  }
  int y = s[0] * 10 + s[1];
  while (true) {
    int a = y / 10;
    int b = y % 10;
    int d = b - a;
    int z = a + d * (n - 1);
    if (0 <= z && z <= 9) {
      int ans = 0;
      rep(i, n) {
        ans *= 10;
        ans += a + d * i;
      }
      if (ans >= x) {
        wt(ans);
        return;
      }
    }
    ++y;
    if (y == 100) {
      ++n;
      y = 10;
    }
  }
}
