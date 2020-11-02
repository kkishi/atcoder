#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<int> a(n);
  cin >> a;
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  int ans = 0;
  map<int, int> seen;
  rep(i, n + 1) {
    ans += seen[s[i] % m];
    ++seen[s[i] % m];
  }
  wt(ans);
}
