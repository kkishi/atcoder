#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<int> x(n);
  V<char> d(n);
  rep(i, n) cin >> x[i] >> d[i];
  {
    V<int> y;
    V<char> e;
    if (d[0] == 'L') {
      y.push_back(0);
      e.push_back('R');
    }
    rep(i, n) {
      y.push_back(x[i]);
      e.push_back(d[i]);
    }
    if (d.back() == 'R') {
      y.push_back(l + 1);
      e.push_back('L');
    }
    swap(x, y);
    swap(d, e);
  }
  int i = 0;
  int ans = 0;
  while (i < sz(x)) {
    int ri = i;
    while (d[ri + 1] == 'R') ++ri;
    int li = ri + 1;
    while (li + 1 < sz(d) && d[li + 1] == 'L') ++li;
    int rd, ld;
    if (ri - i + 1 > li - ri) {
      ld = x[ri + 1];
      rd = ld - 1;
    } else {
      rd = x[ri];
      ld = rd + 1;
    }
    rep(j, i, ri + 1) ans += (rd - (ri - j)) - x[j];
    rep(j, ri + 1, li + 1) ans += x[j] - (ld + j - (ri + 1));
    i = li + 1;
  }
  wt(ans);
}
