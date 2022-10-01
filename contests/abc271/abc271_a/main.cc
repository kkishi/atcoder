#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  string s;
  while (n) {
    int x = n % 16;
    n /= 16;
    if (x < 10) {
      s += '0' + x;
    } else {
      s += 'A' + x - 10;
    }
  }
  while (sz(s) < 2) s += '0';
  reverse(s);
  wt(s);
}
