#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(b);
  int a = 1;
  while (true) {
    int A = Pow(a, a);
    if (A > b) {
      wt(-1);
      return;
    }
    if (A == b) {
      wt(a);
      return;
    }
    ++a;
  }
}
