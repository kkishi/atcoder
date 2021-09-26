#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  rep(i, a, b + 1) if (i % c == 0) {
    wt(i);
    return;
  }
  wt(-1);
}
