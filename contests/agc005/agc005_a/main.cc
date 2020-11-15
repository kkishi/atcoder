#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(x);
  int ans = sz(x);
  int cnt = 0;
  rep(i, sz(x)) {
    if (x[i] == 'T') {
      if (cnt > 0) {
        --cnt;
        ans -= 2;
      }
    } else {
      ++cnt;
    }
  }
  wt(ans);
}
