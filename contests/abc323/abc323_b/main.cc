#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(n);
  V<string> s(n);
  cin >> s;
  rep(i, n) rep(j, n) if (s[i][j] == 'o')++ c[i];
  V<int> idx(n);
  iota(all(idx), 0);
  sort(all(idx), [&](int i, int j) -> bool {
    if (c[i] != c[j]) return c[i] > c[j];
    return i < j;
  });
  each(e, idx)++ e;
  wt(idx);
}
