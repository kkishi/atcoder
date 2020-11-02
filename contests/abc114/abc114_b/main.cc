#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 10000;
  rep(i, s.size() - 2) chmin(ans, abs(stoi(s.substr(i, 3)) - 753));
  wt(ans);
}
