#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int x = 1;
  rep(n) x *= 3;
  rep(i, x) {
    string s;
    int y = i;
    rep(i, n) {
      s = char('a' + y % 3) + s;
      y /= 3;
    }
    wt(s);
  }
}
