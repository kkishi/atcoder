#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  multiset<int> st;
  rep(q) {
    ints(c, x);
    if (c == 1) {
      st.insert(x);
    } else {
      wt([&]() -> int {
        ints(k);
        if (c == 2) {
          auto it = st.lower_bound(x + 1);
          rep(k) {
            if (it == st.begin()) return -1;
            --it;
          }
          return *it;
        } else {
          auto it = st.lower_bound(x);
          rep(k - 1) if (it != st.end())++ it;
          if (it == st.end()) return -1;
          return *it;
        }
      }());
    }
  }
}
