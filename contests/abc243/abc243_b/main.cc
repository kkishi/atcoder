#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  set<int> st(all(a));
  int x = 0;
  each(e, b) if (st.count(e))++ x;
  int y = 0;
  rep(i, n) if (a[i] == b[i])++ y;
  wt(y);
  wt(x - y);
}
