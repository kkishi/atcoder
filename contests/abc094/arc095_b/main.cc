#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  int ai = a[n - 1];
  int aj, ajm = -1;
  rep(i, n - 1) if (chmax(ajm, min(a[i], ai - a[i]))) aj = a[i];
  wt(ai, aj);
}
