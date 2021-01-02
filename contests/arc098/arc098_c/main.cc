#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, q);
  V<int> a(n);
  cin >> a;

  V<int> b = a;
  sort(all(b));

  int ans = big;
  rep(i, n) {  // OK to use x in a if x >= b[i].
    multiset<int> s, r;
    rep(j, n + 1) {
      if (j == n || a[j] < b[i]) {
        while (sz(s) >= k) {
          r.insert(*s.begin());
          s.erase(s.begin());
        }
        s.clear();
      } else {
        s.insert(a[j]);
      }
    }
    if (sz(r) >= q) {
      rep(q - 1) r.erase(r.begin());
      chmin(ans, *r.begin() - b[i]);
    }
  }
  wt(ans);
}
