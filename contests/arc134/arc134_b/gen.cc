#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 6;
  string s;
  Rand r;
  rep(n) s += (char)r.Int('a', 'f');
  wt(n, s);
}
