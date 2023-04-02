#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  set<int> st(all(a));
  each(e, a) if (st.count(e + x)) return true;
  return false;
}

void Main() { wt(Solve()); }
