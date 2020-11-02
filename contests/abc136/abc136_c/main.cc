#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> h(n);
  cin >> h;
  int curr = h[n - 1];
  bool ok = true;
  rrep(i, n - 1) {
    if (h[i] > curr) {
      --h[i];
      if (h[i] > curr) {
        ok = false;
      }
    }
    chmin(curr, h[i]);
  }
  wt(ok);
}
