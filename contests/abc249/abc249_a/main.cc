#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  auto g = [&](int a, int b, int c, int x) {
    int ans = 0;
    rep(i, x) {
      int j = i % (a + c);
      if (j < a) {
        ans += b;
      }
    }
    return ans;
  };
  ints(a, b, c, d, e, f, x);
  int T = g(a, b, c, x);
  int A = g(d, e, f, x);
  if (T > A) {
    wt("Takahashi");
  } else if (T < A) {
    wt("Aoki");
  } else {
    wt("Draw");
  }
}
