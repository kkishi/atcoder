#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  int all = 0;
  each(ai, a) all ^= ai;
  each(ai, a) ai ^= all;
  wt(a);
}
