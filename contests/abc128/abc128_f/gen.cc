#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 100;
  wt(n);
  V<int> s(n);
  Rand r;
  rep(i, n) s[i] = r.Int(-100, 100);
  wt(s);
}
