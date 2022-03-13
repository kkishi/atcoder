#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<int> x(m);
  cin >> x;

  sort(x);
  int ans = x[m - 1] - x[0];

  vector<int> d(m - 1);
  rep(i, m - 1) d[i] = x[i + 1] - x[i];
  sort(d, greater{});

  rep(i, min(n - 1, d.size())) ans -= d[i];
  wt(ans);
}
