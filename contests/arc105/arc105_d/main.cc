#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  if (n & 1) return false;
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  rep(i, n)++ m[a[i]];
  bool ok = true;
  for (auto [_, v] : m)
    if (v & 1) ok = false;
  return !ok;
}

void Main() {
  ints(t);
  rep(t) wt(Solve() ? "First" : "Second");
}
