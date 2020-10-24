#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  bool ans = false;
  rep(n) {
    ints(a);
    if (a & 1) ans = true;
  }
  wt(ans ? "first" : "second");
}
