#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  V<int> hs(h), ws(w);
  rep(i, h) rep(j, w) {
    hs[i] += a[i][j];
    ws[j] += a[i][j];
  }
  rep(i, h) {
    rep(j, w) {
      if (j) cout << ' ';
      cout << hs[i] + ws[j] - a[i][j];
    }
    cout << endl;
  }
}
