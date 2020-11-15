#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, va, vb, l);
  double d = l;
  rep(n) d = d / va * vb;
  wt(d);
}
