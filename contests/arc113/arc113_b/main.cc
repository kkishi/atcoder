#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  a %= 10;
  int A = a;
  int l = 0;
  do {
    (A *= a) %= 10;
    ++l;
  } while (A != a);
  b %= l;
  int x = atcoder::pow_mod(b, c, l);
  if (x == 0) x = l;
  wt(atcoder::pow_mod(a, x, 10));
}
