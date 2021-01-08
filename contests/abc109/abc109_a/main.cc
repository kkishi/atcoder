#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  bool ok = false;
  rep(i, 3) if (!even(a * (i + 1) * b)) ok = true;
  wt(ok);
}
