#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, r);
  V<int> a(n);
  cin >> a;
  int g = 0;
  each(e, a) g ^= (e % (r + l)) / l;
  wt(g == 0 ? "Second" : "First");
}
