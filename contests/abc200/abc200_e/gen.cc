#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 100;
  int k = r.Int(1, n * n * n);
  wt(n, k);
}
