#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  rep(i, sz(s)) {
    if (s[i] == 'g') {
      if (i & 1) {
        ++ans;
      }
    } else if (s[i] == 'p') {
      if (!(i & 1)) {
        --ans;
      }
    }
  }
  wt(ans);
}
