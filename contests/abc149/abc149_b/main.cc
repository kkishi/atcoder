#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, k);
  int c = min(a, k);
  a -= c;
  k -= c;
  c = min(b, k);
  b -= c;
  k -= c;
  wt(a, b);
}
