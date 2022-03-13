#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> p(n);
  cin >> p;
  sort(p);
  wt(accumulate(p.begin(), p.begin() + k, 0));
}
