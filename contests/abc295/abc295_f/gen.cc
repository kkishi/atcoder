#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  Rand r;
  rep(t) {
    string s;
    rep(2) s += (char)r.Int('0', '9');
    wt(s, 1, 10000);
  }
}
