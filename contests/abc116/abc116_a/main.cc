#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  vector<int> v(3);
  cin >> v;
  sort(all(v));
  wt(v[0] * v[1] / 2);
}
