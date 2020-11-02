#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> h(n);
  cin >> h;
  int ans = 0;
  int moved = 0;
  rep(i, 1, n) {
    if (h[i] <= h[i - 1]) {
      ++moved;
      chmax(ans, moved);
    } else {
      moved = 0;
    }
  }
  wt(ans);
}
