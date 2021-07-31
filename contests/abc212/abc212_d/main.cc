#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  multiset<int> st;
  int inc = 0;
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(x);
      st.insert(x - inc);
    } else if (kind == 2) {
      ints(x);
      inc += x;
    } else {
      auto it = st.begin();
      wt(inc + *it);
      st.erase(it);
    }
  }
}
