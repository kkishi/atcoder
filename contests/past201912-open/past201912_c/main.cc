#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(6);
  cin >> v;
  sort(all(v), greater());
  wt(v[2]);
}
