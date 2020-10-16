#include <bits/stdc++.h>

#include "atcoder.h"

int increment(int x) {
  if (x < 10) {
    return x + 1;
  }
  int a = x % 10;
  int b = x / 10 % 10;
  if (a + 1 < 10 && a + 1 <= b + 1) {
    return x + 1;
  }
  int res = increment(x / 10);
  if (res % 10 == 0) {
    return res * 10;
  }
  return res * 10 + (res % 10 - 1);
}

void Main() {
  ints(k);

  int x = 0;
  rep(i, k) x = increment(x);
  wt(x);
}
