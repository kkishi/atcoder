#include <bits/stdc++.h>

#include "atcoder.h"
#include "edit_distance.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  wt(EditDistance(a, b));
}
