#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<V<int>> st;
  rep(n) {
    ints(l);
    V<int> v(l);
    cin >> v;
    st.insert(v);
  }
  wt(sz(st));
}
