#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n), t(m);
  cin >> s >> t;
  set<string> st(all(t));
  int ans = 0;
  each(e, s) if (st.count(e.substr(3)))++ ans;
  wt(ans);
}
