#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> a(3);
  cin >> a;
  sort(a);
  wt(a == V<int>{5, 5, 7} ? "YES" : "NO");
}
