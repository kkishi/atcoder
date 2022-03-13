#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 10;
  int x = r.Int(1, (1 << n) - 1);
  string s;
  while (x) {
    s += (char)('0' + x % 2);
    x /= 2;
  }
  reverse(s);
  wt(n);
  wt(s);
}
