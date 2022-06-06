#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  multiset<int> st;
  st.insert(a[0]);
  rep(i, 1, n) {
    int ai = a[i];
    rep(2) st.insert(ai);
    ans += ai - *st.begin();
    st.erase(st.begin());
  }
  wt(ans);
}
