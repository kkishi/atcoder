#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> a(n);
  cin >> a;
  string h, t;
  rep(i, n) {
    int j = n - 1 - i;
    if (j < i) break;
    if (j == i) {
      h += a[i][0];
      break;
    }
    set<char> is(all(a[i]));
    bool ok = false;
    each(jc, a[j]) if (is.count(jc)) {
      h += jc;
      t += jc;
      ok = true;
      break;
    }
    if (!ok) {
      wt(-1);
      return;
    }
  }
  reverse(t);
  wt(h + t);
}
