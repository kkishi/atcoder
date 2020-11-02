#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> p(n);
  cin >> p;
  wt(accumulate(all(p), 0) - *max_element(all(p)) / 2);
}
