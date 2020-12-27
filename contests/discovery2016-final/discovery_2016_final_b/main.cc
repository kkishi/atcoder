#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, x);
  V<int> t(n), a(n);
  cin >> t >> a;
  V<pair<int, int>> at;
  rep(i, n) at.emplace_back(a[i], t[i]);
  sort(all(at), greater{});

  set<int, greater<>> s;
  rep(i, 100000) s.insert(i + 1);

  int sum = 0;
  int cnt = 0;
  for (auto [a, t] : at) {
    auto it = s.lower_bound(t);
    if (it == s.end()) continue;
    s.erase(it);
    sum += a;
    ++cnt;
    if (sum >= x) {
      wt(cnt);
      return;
    }
  }
  wt(-1);
}
