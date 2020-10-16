#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<short> l(n);
  cin >> l;
  sort(all(l));

  int ans = 0;
  rep(a, n - 2) {
    rep(b, a + 1, n - 1) {
      rep(c, b + 1, n) {
        if (l[c] >= l[a] + l[b]) {
          break;
        }
        ++ans;
      }
    }
  }
  wt(ans);
}
