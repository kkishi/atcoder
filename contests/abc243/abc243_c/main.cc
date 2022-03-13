#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n);
    V<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    strings(s);
    map<int, pair<int, int>> m;
    rep(i, n) {
      if (!m.count(y[i])) {
        m[y[i]] = {big, -big};
      }
      if (s[i] == 'R') {
        chmin(m[y[i]].first, x[i]);
      } else {
        chmax(m[y[i]].second, x[i]);
      }
    }
    each(_, e, m) if (e.first < e.second) return true;
    return false;
  }());
}
