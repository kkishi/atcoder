#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, k);
  bool ok = false;
  rep(ai, k + 1) rep(bi, k + 1) rep(ci, k + 1) if (ai + bi + ci <= k) {
    int A = a << ai, B = b << bi, C = c << ci;
    if (A < B && B < C) ok = true;
  }
  wt(ok);
}
