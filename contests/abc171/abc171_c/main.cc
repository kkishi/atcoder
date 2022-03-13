#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  --n;
  int x = 26;
  int l = 1;
  while (n >= x) {
    n -= x;
    x *= 26;
    ++l;
  }
  string s;
  rep(i, l) {
    s += 'a' + (n % 26);
    n /= 26;
  }
  reverse(s);
  wt(s);
}
