#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(3);
  cin >> v;
  sort(all(v));
  wt(v[0] * v[1] * (v[2] % 2));
}
