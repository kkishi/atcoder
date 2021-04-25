#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int k = r.Int(0, 3);
  string s;
  int n = r.Int(1, 10);
  rep(n) s += (char)('a' + r.Int(0, 4));
  wt(k);
  wt(s);
}
