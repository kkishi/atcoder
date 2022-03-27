#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> st(all(a));
  rep(i, 10000) if (!st.count(i)) {
    wt(i);
    return;
  }
}
