#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k);
  V<int> a(n);
  cin >> a;
  multiset<int> l, r;
  int ls = 0, rs = 0;
  rep(i, m - 1) {
    l.insert(a[i]);
    ls += a[i];
  }
  auto adjust = [&]() {
    while (sz(l) < k) {
      auto it = r.begin();
      ls += *it;
      rs -= *it;
      l.insert(*it);
      r.erase(it);
    }
    while (sz(l) > k) {
      auto it = prev(l.end());
      ls -= *it;
      rs += *it;
      r.insert(*it);
      l.erase(it);
    }
  };
  V<int> ans;
  rep(i, m - 1, n) {
    int add = a[i];
    if (l.empty() || *prev(l.end()) < add) {
      rs += add;
      r.insert(add);
    } else {
      ls += add;
      l.insert(add);
    }
    adjust();
    ans.eb(ls);
    int rem = a[i - (m - 1)];
    if (auto it = l.find(rem); it != l.end()) {
      ls -= *it;
      l.erase(it);
    } else {
      it = r.find(rem);
      assert(it != r.end());
      rs -= *it;
      r.erase(it);
    }
  }
  wt(ans);
}
