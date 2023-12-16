#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> ev(n);
  cin >> ev;
  V<int> p(n);
  V<int> m(n);
  V<int> a;
  rrep(i, n) {
    auto [t, x] = ev[i];
    --x;
    if (t == 1) {
      if (p[x] < m[x]) {
        a.eb(1);
        ++p[x];
      } else {
        a.eb(0);
      }
    } else {
      ++m[x];
    }
  }
  rep(i, n) if (p[i] < m[i]) {
    wt(-1);
    return;
  }
  reverse(a);

  int km = 0;
  int cnt = 0;
  int idx = 0;
  rep(i, n) {
    auto [t, x] = ev[i];
    --x;
    if (t == 1) {
      if (a[idx++]) {
        ++cnt;
        chmax(km, cnt);
      }
    } else {
      --cnt;
    }
  }
  wt(km);
  wt(a);
}
