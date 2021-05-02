#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, s);
  vector a(h, vector(w, int(0)));
  cin >> a;
  int ans = big;
  rep(i, h) rep(j, i + 1, h + 1) rep(k, w) rep(l, k + 1, w + 1) {
    if ((j - i) * (l - k) <= s) {
      set<int> st;
      rep(I, h) rep(J, w) if (!inside(I - i, J - k, j - i, l - k))
          st.insert(a[I][J]);
      chmin(ans, sz(st));
    }
  }
  wt(ans);
}
