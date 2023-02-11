#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m);
  V<int> b(n), c(m);
  cin >> b >> c;
  sort(b);
  dbg(b);
  V<int> ans;
  rep(i, m) {
    int ma = 0;
    V<int> curve;
    rep(j, n) {
      int p = b[j] + c[i];
      chmax(ma, (n - j) * p);
      curve.eb((n - j) * p);
    }
    dbg(c[i], curve);
    rep(i, 1, n - 1) if (curve[i - 1] < curve[i] && curve[i] > curve[i + 1]) {
      dbg(i, curve[i]);
    }
    ans.eb(ma);
  }
  wt(ans);
}
