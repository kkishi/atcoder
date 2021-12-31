#include <bits/stdc++.h>
#include <pbds.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  Set<pair<string, int>> st;
  rep(i, n) {
    strings(s);
    st.insert({s, i});
  }
  rep(q) {
    ints(x);
    strings(t);
    auto it = st.find_by_order(x - 1);
    int idx = it->second;
    st.erase(it);
    st.insert({t, idx});
  }
  V<string> ans(n);
  each(s, i, st) ans[i] = s;
  wt(ans);
}
