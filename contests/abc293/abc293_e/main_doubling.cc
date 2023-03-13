#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(a, x, m);
  wt(Fix([&](auto rec, int x) {
    if (x == 1) return 1 % m;
    if (even(x)) {
      return rec(x / 2) * (Pow(a, x / 2, m) + 1) % m;
    } else {
      return (rec(x - 1) * a + 1) % m;
    }
  })(x));
}
