#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int x = 0, ans = 0;
  rep(i, n) {
    if (s[i] == 'I') {
      ++x;
    } else {
      --x;
    }
    chmax(ans, x);
  }
  wt(ans);
}
