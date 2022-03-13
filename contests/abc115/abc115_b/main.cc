#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> p(n);
  cin >> p;
  wt(accumulate(p) - max(p) / 2);
}
