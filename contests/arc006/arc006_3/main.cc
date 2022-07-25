#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<int> st;
  rep(n) {
    ints(w);
    auto it = st.lower_bound(w);
    if (it == st.end()) {
      st.insert(w);
    } else {
      st.erase(it);
      st.insert(w);
    }
  }
  wt(sz(st));
}
