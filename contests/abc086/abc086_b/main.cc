#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(a, b);
  int x = stoi(a + b);
  bool ok = false;
  rep(i, x) if (i * i == x) ok = true;
  wt(ok);
}
