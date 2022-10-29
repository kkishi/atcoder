#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> h(n);
  cin >> h;
  int ma = -big, ans;
  rep(i, n) if (chmax(ma, h[i])) ans = i + 1;
  wt(ans);
}
