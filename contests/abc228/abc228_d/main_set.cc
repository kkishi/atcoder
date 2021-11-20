#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  const int n = 1 << 20;
  V<int> v(n, -1);
  set<int> st;
  rep(i, n) st.insert(i);
  rep(q) {
    ints(t, x);
    int h = x;
    h %= n;
    if (t == 1) {
      auto it = st.lower_bound(h);
      if (it == st.end()) it = st.begin();
      v[*it] = x;
      st.erase(it);
    } else {
      wt(v[h]);
    }
  }
}
