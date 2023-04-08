#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int ans = 0;
  while (a >= 1 && b >= 1) {
    int g = gcd(a, b);
    dbg(a, b, g, a - g, b - g);
    dbg(a / g, b / g);
    a -= g;
    b -= g;
    ++ans;
  }
  wt(ans);
}
