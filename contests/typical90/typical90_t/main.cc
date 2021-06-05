#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int x = 1;
  rep(b) x *= c;
  wt(a < x);
}
