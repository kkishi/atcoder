#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int ans = 1;
  rep(a - b) ans *= 32;
  wt(ans);
}
