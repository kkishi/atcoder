#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  set<int> st(all(a));
  each(e, a) if (st.count(e + x)) return true;
  return false;
}
