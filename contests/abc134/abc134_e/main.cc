#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  multiset<int, greater<int>> s;
  rep(i, n) {
    auto it = s.upper_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
    }
    s.insert(a[i]);
  }
  wt(s.size());
}
