#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v(1000001);
  v[3] = 1;
  rep(i, 4, n + 1) rep(j, 3)(v[i] += v[i - j - 1]) %= 10007;
  wt(v[n]);
}
