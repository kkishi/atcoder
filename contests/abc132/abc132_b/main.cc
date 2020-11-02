#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> p(n);
  cin >> p;
  int ans = 0;
  rep(i, n - 2) {
    vector<int> v(p.begin() + i, p.begin() + i + 3);
    sort(all(v));
    if (v[1] == p[i + 1]) ++ans;
  }
  wt(ans);
}
