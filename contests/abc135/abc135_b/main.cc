#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> p(n);
  int d = 0;
  rep(i, n) {
    cin >> p[i];
    if (i + 1 != p[i]) ++d;
  }
  wt(d <= 2 ? "YES" : "NO");
}
