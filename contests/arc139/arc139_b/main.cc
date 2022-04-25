#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n, a, b, x, y, z);
    chmin(y, x * a);
    chmin(z, x * b);
    if (a > b) {
      swap(a, b);
      swap(y, z);
    }
    int N;
    if (n < a * b) {
      N = n;
    } else {
      N = n % (a * b) + a * b;
      n -= N;
    }
    int X = n / (a * b) * min({a * b * x, b * y, a * z});
    int Y = big;
    for (int i = 0; i <= N; i += b) {
      int rem = N - i;
      chmin(Y, rem % a * x + rem / a * y + i / b * z);
    }
    wt(X + Y);
  }
}
