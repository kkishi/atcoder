#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int b = accumulate(all(a), 0);
  int c = n - count(all(a), 0);
  wt((b + c - 1) / c);
}
