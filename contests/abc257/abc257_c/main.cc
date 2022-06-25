#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n);
  strings(s);
  V<int> w(n);
  cin >> w;
  V<int> a, c;
  rep(i, n)(s[i] == '0' ? c : a).eb(w[i]);
  sort(a);
  sort(c);
  int ans = 0;
  each(e, w) {
    rep(d, -1, 2) {
      int x = e + d;
      int y = CountLE(c, x) + sz(a) - CountLE(a, x);
      chmax(ans, y);
    }
  }
  wt(ans);
}
