#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  int n = sz(s);
  rep(i, n) {
    if (s[i] == 'U') {
      ans += i * 2 + (n - 1 - i);
    } else {
      ans += i + (n - 1 - i) * 2;
    }
  }
  wt(ans);
}
