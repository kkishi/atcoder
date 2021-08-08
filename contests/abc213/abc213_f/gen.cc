#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 5;
  string s;
  Rand r;
  rep(n) s += (char)('a' + r.Int(0, 3));
  wt(n);
  wt(s);
}
