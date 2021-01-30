#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s, d);
  bool ok = false;
  rep(n) {
    ints(x, y);
    if (x < s && y > d) ok = true;
  }
  wt(ok);
}
