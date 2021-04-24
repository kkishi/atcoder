#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 10;
  int m = 10;
  Rand r;
  wt(n, m);
  set<pair<int, int>> st;
  rep(m) {
    while (true) {
      int a = r.Int(1, n);
      int b = r.Int(1, n);
      if (a == b) continue;
      if (a > b) swap(a, b);
      if (st.count({a, b})) continue;
      st.insert({a, b});
      wt(a, b);
      break;
    }
  }
}
