#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector v(m, vector(3, int(0)));
  cin >> v;
  int ans = -big;
  rep(s, 1 << n) {
    bool ok = true;
    set<int> st;
    each(x, v) {
      int cnt = 0;
      int sum = accumulate(x);
      each(y, x) if (hasbit(s, y - 1)) {
        ++cnt;
        sum -= y;
      }
      if (cnt == 3) ok = false;
      if (cnt == 2) st.insert(sum);
    }
    if (ok) chmax(ans, sz(st));
  }
  wt(ans);
}
