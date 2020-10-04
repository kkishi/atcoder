#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  rep(x, -200, 201) rep(y, -200, 201) if (a == x + y && b == x - y) {
    wt(x, y);
  }
}
