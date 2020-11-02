#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  rep(i, 26) {
    rep(j, 2, 4) {
      for (int k = 0; k + j - 1 < sz(s); ++k) {
        int x = 0;
        rep(l, j) {
          if (s[k + l] == i + 'a') ++x;
        }
        if (x > j / 2) {
          wt(k + 1, k + j);
          return;
        }
      }
    }
  }
  wt(-1, -1);
}
