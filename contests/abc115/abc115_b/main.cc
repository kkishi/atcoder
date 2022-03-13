#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> p(n);
  cin >> p;
  wt(accumulate(p) - *max_element(all(p)) / 2);
}
