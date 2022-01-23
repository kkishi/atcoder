#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n), t(m);
  cin >> s >> t;
  set<string> st(all(t));
  each(e, s) wt(st.count(e) > 0);
}
