#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t, a);
  vector<int> h(n);
  cin >> h;
  int ans;
  double mini = 1e20;
  rep(i, n) if (double d = abs(a - (t - h[i] * 0.006)); d < mini) {
    mini = d;
    ans = i;
  }
  wt(ans + 1);
}
