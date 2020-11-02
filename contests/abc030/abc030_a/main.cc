#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, d);
  int A = b * c, B = a * d;
  wt(A == B ? "DRAW" : A > B ? "TAKAHASHI" : "AOKI");
}
