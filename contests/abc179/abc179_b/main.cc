#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  bool ok = false;
  int cnt = 0;
  rep(n) {
    ints(a, b);
    if (a == b) {
      ++cnt;
    } else {
      cnt = 0;
    }
    if (cnt >= 3) ok = true;
  }
  wt(ok);
}
