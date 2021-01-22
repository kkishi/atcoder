#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = big;
  rep(i, 26) {
    char c = 'a' + i;
    int maxi = 0;
    int x = 0;
    each(si, s) {
      if (si == c) {
        x = 0;
      } else {
        ++x;
      }
      chmax(maxi, x);
    }
    chmin(ans, maxi);
  }
  wt(ans);
}
