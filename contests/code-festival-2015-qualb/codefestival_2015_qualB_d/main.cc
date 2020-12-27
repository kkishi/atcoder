#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<pair<int, int>> st;
  rep(i, n) {
    ints(s, c);
    while (true) {
      auto it = st.lower_bound({s, 0});
      if (it != st.begin() && prev(it)->second > s) {
        auto jt = prev(it);
        c += jt->second - jt->first;
        s = jt->first;
        st.erase(jt);
        continue;
      }
      if (it != st.end() && s + c > it->first) {
        c += it->second - it->first;
        st.erase(it);
        continue;
      }
      wt(s + c - 1);
      st.insert({s, s + c});
      break;
    }
  }
}
