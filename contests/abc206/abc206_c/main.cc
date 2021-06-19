#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  each(e, a)++ m[e];
  int ans = 0;
  each(k, v, m) ans += v * (n - v);
  wt(ans / 2);
}
