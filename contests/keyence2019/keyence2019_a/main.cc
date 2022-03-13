#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(4);
  cin >> v;
  sort(v);
  wt((v == V<int>{1, 4, 7, 9}) ? "YES" : "NO");
}
