#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  multiset<int> st;
  ints(q);
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(x);
      st.insert(x);
    } else if (k == 2) {
      ints(x, c);
      rep(c) {
        auto it = st.find(x);
        if (it == st.end()) break;
        st.erase(it);
      }
    } else {
      auto it = st.begin();
      auto jt = prev(st.end());
      wt(*jt - *it);
    }
  }
}
