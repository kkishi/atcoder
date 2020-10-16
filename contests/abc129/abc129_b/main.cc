#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> w(n);
  cin >> w;
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + w[i];
  int ans = 1000000;
  rep(i, n + 1) chmin(ans, abs(s[n] - 2 * s[i]));
  wt(ans);
}
