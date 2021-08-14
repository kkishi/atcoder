#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    V<pair<int, int>> v;
    rep(n) {
      ints(l, r);
      v.eb(l, r);
    }
    sort(all(v));
    int box = 1;
    multiset<int> st;
    bool ok = true;
    int idx = 0;
    while (idx < sz(v)) {
      if (st.empty()) {
        box = v[idx].first;
      }
      while (idx < sz(v)) {
        auto [l, r] = v[idx];
        if (l > box) break;
        ++idx;
        st.insert(r);
      }
      if (!st.empty()) {
        auto it = st.begin();
        if (box > *it) ok = false;
        ++box;
        st.erase(it);
      }
    }
    while (!st.empty()) {
      auto it = st.begin();
      if (box > *it) ok = false;
      ++box;
      st.erase(it);
    }
    wt(ok);
  }
}
