#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  int maxi = 0;
  for (int ai : a) {
    ++m[ai];
    chmax(maxi, ai);
  }
  int mini = (maxi + 1) / 2;
  rep(i, maxi + 1) {
    int j = max(maxi - i, i);
    --m[j];
    if (m[j] < 0) return false;
  }
  for (auto [k, v] : m)
    if (v > 0 && (k <= mini || maxi < k)) return false;
  return true;
}

void Main() { wt(Solve() ? "Possible" : "Impossible"); }
