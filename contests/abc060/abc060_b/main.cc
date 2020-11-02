#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  bool ok = false;
  rep(i, 1, 100) if (a * i % b == c) ok = true;
  wt(ok ? "YES" : "NO");
}
