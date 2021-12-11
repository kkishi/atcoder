#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(n);
  int ans = 500;
  rep(i, 1, sz(n)) {
    char c = n[i];
    if (c == n[i - 1]) {
      ans += 301;
    } else {
      bool l0 = ('1' <= n[i - 1] && n[i - 1] <= '5');
      bool l1 = ('1' <= c && c <= '5');
      if (l0 == l1) {
        ans += 210;
      } else {
        ans += 100;
      }
    }
  }
  wt(ans);
}
