#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  set<int> st(all(a));
  int mex = 0;
  rep(k) {
    if (st.count(mex)) {
      ++mex;
    }
  }
  wt(mex);
}
