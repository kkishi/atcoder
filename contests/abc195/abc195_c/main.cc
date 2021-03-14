#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int x = n;
  int cnt = 0;
  while (x >= 1000) {
    ++cnt;
    x /= 1000;
  }
  int ans = 0;
  if (cnt >= 1) {
    int t = 1;
    rep(cnt) t *= 1000;
    ans += (n - t + 1) * cnt;
  }
  if (cnt >= 2) {
    int x = 0;
    rep(i, 1, cnt) {
      int y = 999;
      rep(i) y *= 1000;
      ans += y * i;
    }
    ans += x;
  }
  wt(ans);
}
