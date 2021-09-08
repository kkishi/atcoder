#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, q);
  set<int> st = {0, l};
  rep(q) {
    ints(c, x);
    auto [it, ok] = st.insert(x);
    assert(ok);
    if (c == 1) {
      continue;
    }
    wt(*next(it) - *prev(it));
    st.erase(it);
  }
}
