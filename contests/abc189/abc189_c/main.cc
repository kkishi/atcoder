#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  a.pb(0);
  V<pair<int, int>> st;
  int ans = -big;
  rep(i, n + 1) {
    int l = i;
    while (!st.empty()) {
      auto [b, j] = st.back();
      if (b < a[i]) break;
      chmax(ans, (i - j) * b);
      l = j;
      st.pop_back();
    }
    st.pb({a[i], l});
  }
  wt(ans);
}
