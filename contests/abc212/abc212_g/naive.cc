#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(int p) {
  int ans = 0;
  rep(x, p) rep(y, p) {
    bool ok = false;
    int z = x == 0 ? 0 : 1;
    set<int> st;
    while (true) {
      if (st.count(z)) break;
      st.insert(z);
      if (z == y) {
        ok = true;
        break;
      }
      z *= x;
      z %= p;
    }
    if (ok) {
      dbg(x, y);
      ++ans;
    }
  }
  return ans;
}

void Main() {
  ints(p);
  wt(Solve(p));
}
