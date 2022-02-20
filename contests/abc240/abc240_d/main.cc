#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<pair<int, int>> st;
  int cnt = 0;
  rep(i, n) {
    if (st.empty()) {
      st.eb(a[i], 1);
      ++cnt;
    } else {
      int x = st.back().first;
      if (x == a[i]) {
        ++st.back().second;
        ++cnt;
        if (st.back().first == st.back().second) {
          cnt -= st.back().second;
          st.pop_back();
        }
      } else {
        st.eb(a[i], 1);
        ++cnt;
      }
    }
    wt(cnt);
  }
}
