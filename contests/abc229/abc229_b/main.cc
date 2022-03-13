#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(a, b);
  reverse(a);
  reverse(b);
  rep(i, min(sz(a), sz(b))) {
    if (a[i] - '0' + b[i] - '0' >= 10) {
      wt("Hard");
      return;
    }
  }
  wt("Easy");
}
