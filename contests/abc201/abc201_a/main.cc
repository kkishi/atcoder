#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(3);
  cin >> v;
  sort(all(v));
  wt((v[2] - v[1]) == (v[1] - v[0]));
}
