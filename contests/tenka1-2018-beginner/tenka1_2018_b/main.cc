#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, k);
  rep(k) {
    if (a & 1) --a;
    a /= 2;
    b += a;
    swap(a, b);
  }
  if (k & 1) swap(a, b);
  wt(a, b);
}
