#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  int ans = big;
  rep(y, n) {
    int sum = 0;
    multiset<int> s;
    rep(i, y + 1) s.insert(a[(n - i) % n]);
    rep(i, n) {
      sum += *s.begin();
      auto it = s.find(a[(n - y + i) % n]);
      s.erase(it);
      s.insert(a[(i + 1) % n]);
    }
    chmin(ans, sum + x * y);
  }
  wt(ans);
}
