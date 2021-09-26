#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  strings(a, b);
  int A = 0, B = 0;
  each(e, a) A = A * k + e - '0';
  each(e, b) B = B * k + e - '0';
  wt(A * B);
}
