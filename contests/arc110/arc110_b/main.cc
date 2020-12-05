#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(t);
  string s = "110";
  int ans = 0;
  int len = 30000000000;
  rep(offset, 3) {
    bool ok = true;
    rep(i, n) if (s[(i + offset) % 3] != t[i]) ok = false;
    if (ok) ans += 1 + (len - (n + offset)) / 3;
  }
  wt(ans);
}
