#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> a(n + 2);
  rep(i, n) cin >> a[i + 1];
  int tot = 0;
  auto d = [&](int i, int j) { return abs(a[i] - a[j]); };
  rep(i, a.size() - 1) tot += d(i, i + 1);
  rep(i, a.size() - 2) wt(tot - (d(i, i + 1) + d(i + 1, i + 2) - d(i, i + 2)));
}
