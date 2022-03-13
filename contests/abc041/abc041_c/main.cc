#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> a(n);
  rep(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, greater{});
  for (auto& ai : a) wt(ai.second + 1);
}
