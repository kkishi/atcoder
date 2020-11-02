#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  rep(h, 1, 3501) rep(n, h, 3501) {
    int denominator = 4 * h * n - N * (n + h);
    int numerator = N * h * n;
    if (denominator > 0 && numerator % denominator == 0) {
      wt(h, n, numerator / denominator);
      return;
    }
  }
}
