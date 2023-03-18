#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, p, q, r);
    V<int> a(n);
    cin >> a;
    V<int> s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    set<int> st(s.begin() + 1, s.end());
    rep(i, n) {
      if (st.count(p + s[i]) && st.count(p + q + s[i]) &&
          st.count(p + q + r + s[i]))
        return true;
    }
    return false;
  }());
}
