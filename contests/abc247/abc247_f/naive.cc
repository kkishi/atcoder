#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n), q(n);
  cin >> p >> q;
  int ans = 0;
  rep(mask, 1 << n) {
    set<int> st;
    rep(i, n) if (hasbit(mask, i)) {
      st.insert(p[i]);
      st.insert(q[i]);
    }
    if (sz(st) == n) {
      string s;
      rep(i, n) s += (char)('0' + hasbit(mask, i));
      dbg(s);
      ++ans;
    }
  }
  wt(ans);
}
