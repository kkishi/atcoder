#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> t(n);
  set<pair<int, int>, greater<>> one, two;
  rep(i, n) {
    ints(k);
    t[i].resize(k);
    cin >> t[i];
    rep(j, min(2, k)) {
      int x = t[i][j];
      if (j == 0) one.insert({x, i});
      two.insert({x, i});
    }
    reverse(all(t[i]));
  }
  ints(m);
  rep(m) {
    ints(a);
    auto [x, i] = *(a == 1 ? one : two).begin();
    wt(x);
    if (auto it = one.find({x, i}); it != one.end()) one.erase(it);
    if (auto it = two.find({x, i}); it != two.end()) two.erase(it);
    if (t[i].back() == x) {
      t[i].pop_back();
      if (t[i].size() >= 1) one.insert({t[i].back(), i});
      if (t[i].size() >= 2) two.insert({t[i][t[i].size() - 2], i});
    } else {
      assert(t[i].size() >= 2);
      t[i][t[i].size() - 2] == x;
      int y = t[i].back();
      rep(2) t[i].pop_back();
      t[i].push_back(y);
      if (t[i].size() >= 2) two.insert({t[i][t[i].size() - 2], i});
    }
  }
}
