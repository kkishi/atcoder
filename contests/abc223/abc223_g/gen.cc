#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 6;
  wt(n);
  Rand r;
  auto v = r.Tree(n);
  each(a, b, v) wt(a, b);
}
