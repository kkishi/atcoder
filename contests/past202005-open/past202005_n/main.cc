#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);

  V<int> a(n + 2);
  rep(i, n + 2) a[i] = i;

  // Each element i of st satisfies a[i] > a[i+1].
  set<int> st;

  rep(q) {
    ints(t, x, y);
    auto swp = [&](int x) {
      rep(i, x - 1, x + 2) st.erase(i);
      swap(a[x], a[x + 1]);
      rep(i, x - 1, x + 2) if (a[i] > a[i + 1]) st.insert(i);
    };
    if (t == 1) {
      swp(x);
    } else {
      while (true) {
        auto it = st.lower_bound(x);
        if (it == st.end() || *it >= y) break;
        st.erase(it);
        swp(*it);
      }
    }
  }
  wt(V<int>(a.begin() + 1, a.end() - 1));
}
