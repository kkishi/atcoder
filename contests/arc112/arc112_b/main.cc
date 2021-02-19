#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(b, c);
  int A = -b - (c - 1) / 2;
  int B = -b + (c - 1) / 2;
  int C = b - c / 2;
  int D = b + (c - 2) / 2;
  if (B < C) {
    int L = B - A + 1;
    int R = D - C + 1;
    wt(L + R);
  } else {
    int MA = max({A, B, C, D});
    int MI = min({A, B, C, D});
    wt(MA - MI + 1);
  }
}
