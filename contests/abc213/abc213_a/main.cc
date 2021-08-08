#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  rep(c, 1000) if ((a ^ c) == b) {
    wt(c);
    return;
  }
}
