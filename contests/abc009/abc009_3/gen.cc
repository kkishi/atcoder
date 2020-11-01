#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Random r;
  int n = 10, k = r.Int(1, n);
  wt(n, k);
  string s;
  rep(n) s += r.Alpha();
  wt(s);
}
