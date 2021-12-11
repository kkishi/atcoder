#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(n) {
    ints(a, b);
    int c = b - a;
    c %= 100;
    ans += c / 50;
    c %= 10;
    ans += c / 5;
  }
  wt(ans);
}
