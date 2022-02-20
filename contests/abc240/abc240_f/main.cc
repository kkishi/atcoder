#include <bits/stdc++.h>

#include "atcoder.h"
#include "numeric_sequence.h"

void Solve() {
  ints(n, m);
  int ans = -big;
  int a = 0;
  int b = 0;
  rep(i, n) {
    ints(x, y);
    // Check the next element.
    chmax(ans, a + b + x);
    if (x < 0 && b > 0) {
      int z = b / -x;
      if (z <= y) {
        // Check the element right before b becomes negative.
        chmax(ans, a + ArithmeticProgressionSum(b + x, x, z));
      }
    }
    a += ArithmeticProgressionSum(b + x, x, y);
    b += x * y;
    chmax(ans, a);
  }
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
