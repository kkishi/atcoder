#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(n);
  int ans = 500;
  rep(i, 1, sz(n)) {
    char a = n[i - 1], b = n[i];
    if (a == b) {
      ans += 301;
    } else {
      if (('1' <= a && a <= '5') == ('1' <= b && b <= '5')) {
        ans += 210;
      } else {
        ans += 100;
      }
    }
  }
  wt(ans);
}
