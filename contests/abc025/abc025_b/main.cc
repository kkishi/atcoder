#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  int x = 0;
  rep(n) {
    strings(s);
    ints(d);
    d = min(max(a, d), b);
    if (s == "West") d = -d;
    x += d;
  }
  if (x < 0) {
    cout << "West ";
    x = -x;
  } else if (x > 0) {
    cout << "East ";
  }
  wt(x);
}
