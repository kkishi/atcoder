#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = r.Int(1, 100);
  string s;
  rep(i, n) {
    int x = r.Int(0, 2);
    if (x == 0) s += 'B';
    if (x == 1) s += 'W';
    if (x == 2) s += 'R';
  }
  wt(n);
  wt(s);
}
