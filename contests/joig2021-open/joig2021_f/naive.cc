#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, s);
  vector a(h, vector(w, int(0)));
  cin >> a;
  int ans = big;
  rep(i, h) for (int j = i; j < h && (j - i + 1) <= s; ++j) {
    rep(k, w) for (int l = k; l < w && (j - i + 1) * (l - k + 1) <= s; ++l) {
      set<int> st;
      rep(I, h) rep(J, w) if (!inside(I - i, J - k, j - i + 1, l - k + 1))
          st.insert(a[I][J]);
      chmin(ans, sz(st));
    }
  }
  wt(ans);
}
