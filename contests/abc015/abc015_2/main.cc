#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int b = accumulate(a);
  int c = n - count(all(a), 0);
  wt(div_ceil(b, c));
}
