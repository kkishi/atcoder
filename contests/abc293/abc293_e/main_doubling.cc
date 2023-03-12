#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(a, x, m);
  wt(Fix([&](auto rec, int x) {
    if (x == 1) return 1 % m;
    if (even(x)) {
      int res = rec(x / 2);
      return (res * Pow(a, x / 2, m) + res) % m;
    } else {
      return (rec(x - 1) * a + 1) % m;
    }
  })(x));
}
