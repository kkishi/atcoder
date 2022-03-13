#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  if (n == 0) {
    wt("0");
    return;
  }
  string s;
  while (n) {
    int x = n % 36;
    s += x < 10 ? ('0' + x) : ('A' + x - 10);
    n /= 36;
  }
  reverse(s);
  wt(s);
}
