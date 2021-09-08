#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  multiset<int> st;
  deque<int> v;
  rep(q) {
    ints(c);
    if (c == 1) {
      ints(x);
      v.pb(x);
    } else if (c == 2) {
      if (!st.empty()) {
        auto it = st.begin();
        wt(*it);
        st.erase(it);
      } else {
        wt(v.front());
        v.pop_front();
      }
    } else {
      while (!v.empty()) {
        st.insert(v.front());
        v.pop_front();
      }
    }
  }
}
