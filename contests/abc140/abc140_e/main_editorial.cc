#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;

  V<pair<int, int>> v;
  rep(i, n) v.emplace_back(p[i], i);
  sort(all(v), greater());

  set<int> s;
  s.insert(-1);
  s.insert(n);

  int ans = 0;
  for (auto [pi, i] : v) {
    auto [it, _] = s.insert(i);
    auto l = prev(it), r = next(it);
    int x = 0;
    if (next(r) != s.end()) {
      x += (i - *l) * (*next(r) - *r);
    }
    if (l != s.begin()) {
      x += (*l - *prev(l)) * (*r - i);
    }
    ans += x * pi;
  }
  wt(ans);
}
