#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"

void Main() {
  int a = 14, b = 35, c = a, d = 1;
  int g = gcd(a, b);
  dbg(g);
  while (true) {
    c += a;
    c %= b;
    ++d;
    dbg(c, d, c / g);
    if (c == a) break;
  }
}
