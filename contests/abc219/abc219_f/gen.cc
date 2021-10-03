#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  string s;
  int l = 2000;
  rep(l) s += "LRUD"[r.Int(0, 3)];
  int k = 100LL;
  wt(s);
  wt(k);
}
