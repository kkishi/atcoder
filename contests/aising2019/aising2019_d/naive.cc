#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  rep(q) {
    ints(x);
    set<int> s(all(a));
    int ans = 0;
    rep(i, n) {
      if (i % 2 == 0) {
        auto it = prev(s.end());
        ans += *it;
        s.erase(it);
      } else {
        auto it = s.lower_bound(x);
        if (it == s.end()) {
          --it;
        }
        if (it != s.begin()) {
          auto jt = prev(it);
          if (abs(*jt - x) <= abs(*it - x)) {
            --it;
          }
        }
        s.erase(it);
      }
    }
    wt(ans);
  }
}
